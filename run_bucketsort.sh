#!/bin/bash

# Cores
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m'


read -p "Enter size of array: " size

echo -e "${BLUE}Compiling test case maker"
gcc makeTestCase.c -o makeTestCase.exe
echo -e "${GREEN}Compiling successfully done - created test case with ${size}"

./makeTestCase.exe case_1.txt "${size}"
./makeTestCase.exe case_2.txt "${size}"
./makeTestCase.exe case_3.txt "${size}"

echo -e "${GREEN}Test cases are created";

echo -e "${BLUE}Compiling test case maker"
gcc -fopenmp main.c -o main.exe
echo -e "${GREEN}Compiling successfully done"

./main.exe case_1.txt result_case_1.txt "${size}"
./main.exe case_2.txt result_case_2.txt "${size}"
./main.exe case_3.txt result_case_3.txt "${size}"

echo -e "${GREEN}Done"