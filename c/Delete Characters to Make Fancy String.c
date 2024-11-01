#include <stdio.h>
#include <string.h>

char* makeFancyString(char* s) {
    int n = strlen(s);
    if (n < 3) return s;

    int writeIndex = 1;
    for (int i = 2; i < n; ++i) {
        if (!(s[i] == s[writeIndex] && s[i] == s[writeIndex - 1])) {
            s[++writeIndex] = s[i];
        }
    }
    s[writeIndex + 1] = '\0';
    return s;
}

// Test cases
int main() {
    char s1[] = "leeetcode";
    char original_s1[sizeof(s1)];
    strcpy(original_s1, s1);  
    printf("Input: %s Output: %s\n", original_s1, makeFancyString(s1));

    char s2[] = "aaabaaaa";
    char original_s2[sizeof(s2)];
    strcpy(original_s2, s2);
    printf("Input: %s Output: %s\n", original_s2, makeFancyString(s2));

    char s3[] = "aab";
    char original_s3[sizeof(s3)];
    strcpy(original_s3, s3);
    printf("Input: %s Output: %s\n", original_s3, makeFancyString(s3));

    return 0;
}


