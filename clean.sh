#!/bin/bash

# Cores
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m'


echo -e "${RED}Cleaning..."
[ -e results_fibo1.txt ] && rm result_case1.txt
[ -e results_fibo2.txt ] && rm result_case2.txt
[ -e result_case_1.txt ] && rm result_case_1.txt
[ -e result_case_2.txt ] && rm result_case_2.txt
[ -e result_case_3.txt ] && rm result_case_3.txt

[ -e main.exe ] && rm main.exe
[ -e fibo-1.exe ] && rm fibo-1.exe
[ -e fibo-2.exe ] && rm fibo-2.exe

echo -e "${GREEN}Done!"