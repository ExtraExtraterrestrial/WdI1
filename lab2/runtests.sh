#!/bin/bash

for f in src/*.c; do
    out="${f##*/}"
    out="${out%%.*}"
    gcc -s $f -o $out -lm && ./$out
done