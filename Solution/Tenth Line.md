# 📜Tenth Line

## 🛠️Approach
🤔 We'll use a series of conditional statements to determine our actions based on the number of lines in the "file.txt":
- If the file exists, we'll proceed to count its lines.
- If the number of lines is 10 or more, we'll use `sed` to print the tenth line.
- If the file doesn't exist, we'll output an error message.

## Code
```bash
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
