import http.server
import json
import os
import subprocess
import re

# ================= CONFIGURATION =================

BASE_DIR = os.getcwd()

CPP_TEMPLATE = """#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    // Your code here
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
"""

RUN_SH_TEMPLATE = r"""#!/bin/bash
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m'

MAX_LINES=20
declare -a VERDICTS=()
declare -a TIMES=()
declare -a NUMS=()

echo "⚙️ Compiling main.cpp..."
g++ -std=c++23 -O2 -Wall main.cpp -o solution

if [ $? -ne 0 ]; then
    echo -e "${RED}❌ Compilation Failed!${NC}"
    exit 1
fi
echo -e "${GREEN}✅ Compilation Successful!${NC}\n"

for in_file in in*.txt; do [ -e "$in_file" ] || continue
    num=${in_file//[^0-9]/}
    out_file="out${num}.txt"
    res_file="res${num}.txt"

    if [ ! -f "$out_file" ]; then continue; fi

    echo "----------------------------------------"
    echo "🏃 Running Test $num..."

    start=$(date +%s%N)
    ./solution < "$in_file" > "$res_file"
    end=$(date +%s%N)

    runtime=$(( (end - start) / 1000000 ))

    if diff -wB "$out_file" "$res_file" > /dev/null; then
        echo -e "${GREEN}✅ PASSED${NC} (${runtime}ms)"
        VERDICTS+=("ACCEPTED")
        TIMES+=("${runtime} ms")
    else
        echo -e "${RED}❌ FAILED${NC} (${runtime}ms)"
        echo -e "\nExpected:"
        head -n "$MAX_LINES" "$out_file"
        out_lines=$(wc -l < "$out_file")
        if [ "$out_lines" -gt "$MAX_LINES" ]; then
            echo -e "${YELLOW}... (truncated, $((out_lines - MAX_LINES)) more lines)${NC}"
        fi
        echo -e "\nGot:"
        head -n "$MAX_LINES" "$res_file"
        res_lines=$(wc -l < "$res_file")
        if [ "$res_lines" -gt "$MAX_LINES" ]; then
            echo -e "${YELLOW}... (truncated, $((res_lines - MAX_LINES)) more lines)${NC}"
        fi
        echo ""
        VERDICTS+=("WRONG ANSWER")
        TIMES+=("${runtime} ms")
    fi
    NUMS+=("$num")
done

# Summary Table
if [ ${#NUMS[@]} -gt 0 ]; then
    echo ""
    echo "=============================================="
    printf "  %-3s | %-20s | %s\n" "#" "verdict" "time"
    echo "----------------------------------------------"
    overall="${GREEN}ACCEPTED${NC}"
    for i in "${!NUMS[@]}"; do
        if [ "${VERDICTS[$i]}" = "ACCEPTED" ]; then
            color="${GREEN}"
        else
            color="${RED}"
        fi
        printf "  %-3s | ${color}%-20s${NC} | %s\n" "${NUMS[$i]}" "${VERDICTS[$i]}" "${TIMES[$i]}"
        if [ "${VERDICTS[$i]}" != "ACCEPTED" ] && [ "$overall" = "${GREEN}ACCEPTED${NC}" ]; then
            overall="${RED}${VERDICTS[$i]}${NC}"
        fi
    done
    echo "----------------------------------------------"
    echo -e "Result: ${overall}"
    echo "=============================================="
fi
"""

ZED_TASKS_TEMPLATE = """[
    {
        "label": "1. Judge: Run All Tests",
        "command": "cd '${ZED_DIRNAME}' && ./run.sh",
        "use_new_terminal": false,
        "allow_concurrent_runs": false
    },
    {
        "label": "2. Judge: Submit to CSES",
        "command": "cd '${ZED_DIRNAME}' && ./submit.sh",
        "use_new_terminal": false,
        "allow_concurrent_runs": false
    }
]"""

# =================================================

def sanitize_name(name):
    return re.sub(r'[^\w\-_\. ]', '_', name)

class CompanionHandler(http.server.BaseHTTPRequestHandler):
    def do_POST(self):
        content_length = int(self.headers['Content-Length'])
        body = self.rfile.read(content_length).decode('utf-8')
        data = json.loads(body)

        self.send_response(200)
        self.send_header('Access-Control-Allow-Origin', '*')
        self.end_headers()

        problem_name = sanitize_name(data.get('name', 'problem'))
        prob_dir = os.path.join(BASE_DIR, problem_name)
        os.makedirs(prob_dir, exist_ok=True)

        # 1. Update Zed Tasks
        zed_dir = os.path.join(BASE_DIR, ".zed")
        os.makedirs(zed_dir, exist_ok=True)
        with open(os.path.join(zed_dir, "tasks.json"), 'w', encoding='utf-8') as f:
            f.write(ZED_TASKS_TEMPLATE)

        # 2. Create C++ file
        src_file = os.path.join(prob_dir, "main.cpp")
        if not os.path.exists(src_file):
            with open(src_file, 'w', encoding='utf-8') as f:
                f.write(CPP_TEMPLATE)

        # 3. Create the Local Judge run.sh
        run_script = os.path.join(prob_dir, "run.sh")
        with open(run_script, 'w', encoding='utf-8') as f:
            f.write(RUN_SH_TEMPLATE)
        os.chmod(run_script, 0o755)

        # 4. IF THIS IS A CSES PROBLEM -> Auto-generate the submit.sh script!
        url = data.get('url', '')
        # Dynamically extract BOTH the Course (e.g. problemset) and Task ID (e.g. 1069)
        match = re.search(r'cses\.fi/([^/]+)/task/(\d+)', url)

        if match:
            course = match.group(1)
            problem_id = match.group(2)
            submit_script = os.path.join(prob_dir, "submit.sh")

            with open(submit_script, 'w', encoding='utf-8') as f:
                f.write(f"""#!/bin/bash
GREEN='\\033[0;32m'
RED='\\033[0;31m'
NC='\\033[0m'

if ! command -v cses-cli &> /dev/null; then
    echo -e "${{RED}}❌ 'cses-cli' is not installed.${{NC}}"
    echo "Please install it by running: cargo install cses-cli"
    exit 1
fi

echo -e "${{GREEN}}🌐 Selected CSES Problem: {problem_id} (Course: {course})${{NC}}"
echo -e "🚀 Submitting main.cpp to CSES...\\n"

# Pass both course and task dynamically so cses-cli knows exactly where to submit!
cses-cli submit --course {course} --task {problem_id} main.cpp
""")
            os.chmod(submit_script, 0o755)

        # 5. Extract Tests
        tests = data.get('tests',[])
        for i, test in enumerate(tests, 1):
            with open(os.path.join(prob_dir, f"in{i}.txt"), 'w', encoding='utf-8') as f:
                f.write(test.get('input', ''))
            with open(os.path.join(prob_dir, f"out{i}.txt"), 'w', encoding='utf-8') as f:
                f.write(test.get('output', ''))

        print(f"\n✅ Parsed: {problem_name}")

        try:
            subprocess.run(["zed", BASE_DIR, src_file])
        except Exception as e:
            print(f"⚠️ Failed to open Zed: {e}")

    def do_OPTIONS(self):
        self.send_response(200)
        self.send_header('Access-Control-Allow-Origin', '*')
        self.send_header('Access-Control-Allow-Methods', 'POST, GET, OPTIONS')
        self.send_header('Access-Control-Allow-Headers', 'Content-Type')
        self.end_headers()

    def log_message(self, format, *args):
        pass

if __name__ == '__main__':
    server_address = ('localhost', 10043)
    httpd = http.server.HTTPServer(server_address, CompanionHandler)

    print("🎧 Listening on port 10043 for Competitive Companion...")
    print(f"📂 Workspace root: {BASE_DIR}")
    print("Press Ctrl+C to stop.")

    try:
        httpd.serve_forever()
    except KeyboardInterrupt:
        print("\nStopping server...")
