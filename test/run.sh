#!/bin/bash

rm test.exe
gcc -o test.exe main.c -s -static -lpthread -std=c99
./test.exe
