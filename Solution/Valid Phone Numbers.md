# 📞 Valid Phone Numbers Bash Script 📞

## Intuition
🤔 The task is to extract and print all valid phone numbers from a text file.

## Approach
💡 To accomplish this, I use the `grep` command-line utility with a regular expression pattern to search for valid phone number formats in the given text file. The regular expression pattern matches phone numbers in the format (xxx) xxx-xxxx or xxx-xxx-xxxx, where x represents a digit. I then print all the matching lines, which correspond to valid phone numbers.

# Code
```bash
#!/bin/bash

filename="file.txt"

pattern="^(\([0-9]{3}\) [0-9]{3}-[0-9]{4}|[0-9]{3}-[0-9]{3}-[0-9]{4})$"

grep -E "$pattern" "$filename"
