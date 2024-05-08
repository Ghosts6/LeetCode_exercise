# Word Frequency Bash Script 📊

## Intuition
🤔 Counting the frequency of each word in a text file can be done efficiently using a Bash script. 

## Approach
💡 We read the words from the file into an array, then iterate through each word, counting its occurrences using an associative array. Finally, we print each word along with its frequency, sorted by frequency in descending order.

# Bash Script
```bash
#!/bin/bash

words=($(<words.txt))
declare -A word_counts

for word in "${words[@]}"; do
    ((word_counts[$word]++))
done  

for word in "${!word_counts[@]}"; do
    echo "$word ${word_counts[$word]}"
done | sort -k2nr