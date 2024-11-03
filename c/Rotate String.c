#include <stdio.h>
#include <stdbool.h>
#include <string.h>


bool rotateString(char* s, char* goal) {
    int lenS = strlen(s);
    int lenGoal = strlen(goal);
    
    if (lenS != lenGoal) {
        return false;
    }

    char doubleS[2 * lenS + 1];
    snprintf(doubleS, sizeof(doubleS), "%s%s", s, s);

    return strstr(doubleS, goal) != NULL;
}
// Test cases
int main() {
    char* s1 = "abcde";
    char* goal1 = "cdeab";
    printf("Test 1: %s\n", rotateString(s1, goal1) ? "true" : "false"); // Expected output: true

    char* s2 = "abcde";
    char* goal2 = "abced";
    printf("Test 2: %s\n", rotateString(s2, goal2) ? "true" : "false"); // Expected output: false
    
    return 0;
}
