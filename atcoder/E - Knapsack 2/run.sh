#!/bin/bash
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

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
    else
        echo -e "${RED}❌ FAILED${NC} (${runtime}ms)"
        echo -e "\nExpected:"
        cat "$out_file"
        echo -e "\nGot:"
        cat "$res_file"
        echo ""
    fi
done
echo "----------------------------------------"
