#!/bin/bash

filename="file.txt"

pattern="^(\([0-9]{3}\) [0-9]{3}-[0-9]{4}|[0-9]{3}-[0-9]{3}-[0-9]{4})$"

grep -E "$pattern" "$filename"

# filename="file.txt"

# while IFS= read -r line; do

#     if [[ $line =~ ^(\([0-9]{3}\) |[0-9]{3}-)[0-9]{3}-[0-9]{4}$ ]]; then
#         echo "$line"
#     fi
# done < "$filename