#!/bin/bash

gcc -s src/main.c src/utils.c -o main -lc && ./main
