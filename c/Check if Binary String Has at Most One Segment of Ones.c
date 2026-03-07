#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Protype
bool checkOnesSegment(char* s);

// Test cases
int main() {
    // case 1
    char s1[] = "1001"; 
    printf("Result of test case 1 : %d\n", checkOnesSegment(s1)); // Expected: 0

    // case 2
    char s2[] = "110";
    printf("Result of test case 2 : %d\n", checkOnesSegment(s2)); // Expected: 1
}

bool checkOnesSegment(char* s) {
    bool started = false, ended = false;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '1') {
            if (ended) return false;
            started = true;
        } else if (started) {
            ended = true;
        }
    }

    return true;
}
