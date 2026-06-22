#!/bin/bash
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
