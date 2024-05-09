# Transpose File Bash Script 🔄

## Intuition
🤔 The task is to transpose the content of a text file, which involves switching rows and columns.

## Approach
💡 To accomplish this, I use the `awk` command-line utility. I iterate through each field of the input file, storing them in an array indexed by the field number. Then, in the `END` block, I print the elements of the array, effectively transposing the file.

# Code
```
#!/bin/bash

awk '{
    for (i = 1; i <= NF; i++) {
        if (NR == 1) {
            arr[i] = $i;
        } else {
            arr[i] = arr[i] " " $i;
        }
    }
} END {
    for (i = 1; i <= NF; i++) {
        print arr[i];
    }
}' file.txt

```