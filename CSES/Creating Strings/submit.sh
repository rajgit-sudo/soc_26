#!/bin/bash
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

if ! command -v cses-cli &> /dev/null; then
    echo -e "${RED}❌ 'cses-cli' is not installed.${NC}"
    echo "Please install it by running: cargo install cses-cli"
    exit 1
fi

echo -e "${GREEN}🌐 Selected CSES Problem: 1622 (Course: problemset)${NC}"
echo -e "🚀 Submitting main.cpp to CSES...\n"

# Pass both course and task dynamically so cses-cli knows exactly where to submit!
cses-cli submit --course problemset --task 1622 main.cpp
