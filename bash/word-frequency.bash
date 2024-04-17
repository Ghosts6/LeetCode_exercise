#!/bin/bash

words=($(<words.txt))
declare -A word_counts

for word in "${words[@]}"; do
    ((word_counts[$word]++))
done