#!/bin/bash

file="file.txt"

if [ -f "$file" ]; then
    lines=$(wc -l < "$file")

    if (( lines >= 10 )); then
        sed -n '10p' "$file"
    fi
else
    echo "File '$file' does not exist."
fi