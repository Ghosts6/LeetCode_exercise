# 🔍Word Frequency Counter in Bash 

## Problem Description
📝 **Task**: Given a text file, count the frequency of each word and display the results in descending order of frequency.

## Intuition
🤔 Counting word frequencies in a file can be efficiently accomplished with a Bash script. This approach is lightweight and leverages Bash's built-in associative arrays to store and manage the count for each word.

## Approach
💡 **Steps**:
1. **Read**: Load all words from the file into an array.
2. **Count**: Iterate through each word, using an associative array to track occurrences.
3. **Sort & Print**: Display each word with its frequency, sorted by frequency in descending order.

This approach ensures that we process each word in a single pass (for counting), followed by another pass for sorting and printing.

## Complexity Analysis 📊

- **Time Complexity**: O(n log n)
  - *Counting words*: O(n), where \( n \) is the total number of words.
  - *Sorting*: O(n log n) for sorting by frequency.
  
- **Space Complexity**: O(u)
  - *Memory*: O(u), where \( u \) is the number of unique words, as each unique word requires space in the associative array.

## Solution Code 💻
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
```