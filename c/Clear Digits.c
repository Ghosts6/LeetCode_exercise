#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* clearDigits(const char *s) {
    int len = strlen(s), top = -1;
    char *stack = (char*)malloc(len + 1);

    for (int i = 0; i < len; i++) {
        if (isdigit(s[i])) {
            if (top >= 0) top--;
        } else {
            stack[++top] = s[i];  
        }
    }

    stack[top + 1] = '\0';
    return stack;
}
// Test cases
int main() {
    char *result;
    // case 1
    result = clearDigits("abc");
    printf("Output of test case 1: \"%s\"\n", result); // Expected Output: "abc"
    free(result);
    // case 2
    result = clearDigits("cb34");
    printf("Output of test case 2: \"%s\"\n", result); // Expected Output: ""
    free(result);
    // case 3
    result = clearDigits("a1b2c3");
    printf("Output of test case 3 : \"%s\"\n", result); // Expected Output: ""
    free(result);

    return 0;
}
