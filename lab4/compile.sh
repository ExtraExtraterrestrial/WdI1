#!/bin/bash

for f in src/*.c; do
    out="${f##*/}"
    out="${out%%.*}"
    gcc -s $f -o $out -lm
done

./generate_logs.sh
./log_report data/app.log results/log_report.txt
./measurements <<< "5 -89.1 50 0 -15.1 23"
./students 3.5 > results/students_report.txt

ls -1 results