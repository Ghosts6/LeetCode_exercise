#!/bin/bash

filename="file.txt"

while IFS= read -r line; do

    if [[ $line =~ ^(\([0-9]{3}\) |[0-9]{3}-)[0-9]{3}-[0-9]{4}$ ]]; then
        echo "$line"
    fi
done < "$filename"