#!/bin/bash

rm test.exe
gcc -o test.exe main.c -s -static -lpthread -lm -std=gnu99 -Wall -Wextra -Wshadow
./test.exe
