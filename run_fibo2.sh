#!/bin/bash


# Cores
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m'

read -p "Entering Fibonacci number: " size

echo -e "${RED}Deleting old results..."
[ -e results_fibo2.txt ] && rm results_fibo2.txt

echo -e "${BLUE}Compiling..."
gcc -fopenmp fibo-2.c -o fibo-2.exe
echo -e "${GREEN}Compiling successfully done"

echo -e "${NC}Fibonacci for ${size}"
echo -e "${YELLOW}Wait please${NC}"
./fibo-2.exe ${size} >> results_fibo2.txt
./fibo-2.exe ${size} >> results_fibo2.txt
./fibo-2.exe ${size} >> results_fibo2.txt
./fibo-2.exe ${size} >> results_fibo2.txt
./fibo-2.exe ${size} >> results_fibo2.txt
./fibo-2.exe ${size} >> results_fibo2.txt
./fibo-2.exe ${size} >> results_fibo2.txt
./fibo-2.exe ${size} >> results_fibo2.txt
./fibo-2.exe ${size} >> results_fibo2.txt
./fibo-2.exe ${size} >> results_fibo2.txt

echo -e "${GREEN}Done!${NC}"