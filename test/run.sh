#!/bin/bash

rm test*
gcc -o test main.c -s -static -lpthread -lm -std=gnu99 -Wall -Wextra -Wshadow
./test*
