#!/bin/bash

read -p "Enter size of array: " size

echo "Compiling test case maker"
gcc makeTestCase.c -o makeTestCase.exe
echo "Compiling successfully done - created test case with ${size}"

./makeTestCase.exe case_1.txt "${size}"
./makeTestCase.exe case_2.txt "${size}"
./makeTestCase.exe case_3.txt "${size}"

echo "Test cases are created";

echo "Compiling test case maker"
gcc -fopenmp main.c -o main.exe
#gcc main.c -o main.exe
echo "Compiling successfully done"

./main.exe case_1.txt result_case_1.txt "${size}"
./main.exe case_2.txt result_case_2.txt "${size}"
./main.exe case_3.txt result_case_3.txt "${size}"