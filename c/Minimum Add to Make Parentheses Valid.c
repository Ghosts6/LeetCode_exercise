#include <stdio.h>

int minAddToMakeValid(char* s) {
    int open = 0, close = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            open++;
        } else if (s[i] == ')') {
            if (open > 0) {
                open--;
            } else {
                close++;
            }
        }
    }
    
    return open + close;
}

int main() {
    // case 1
    char s1[] = "())";
    printf("Input: %s - Output: %d\n", s1, minAddToMakeValid(s1)); // Expected: 1
    
    // case 2
    char s2[] = "(((";
    printf("Input: %s - Output: %d\n", s2, minAddToMakeValid(s2)); // Expected: 3
    
    // Additional case
    char s3[] = "()";
    printf("Input: %s - Output: %d\n", s3, minAddToMakeValid(s3)); // Expected: 0
        
    return 0;
}
