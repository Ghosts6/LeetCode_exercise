#include <stdio.h>
#include <string.h>

int findTheLongestSubstring(char* s) {
    int n = strlen(s);

    int first_occurrence[32];
    for (int i = 0; i < 32; i++) {
        first_occurrence[i] = -1;
    }

    first_occurrence[0] = 0;

    int mask = 0;
    int max_len = 0;

    for (int i = 0; i < n; i++) {
        switch (s[i]) {
            case 'a': mask ^= (1 << 0); break;
            case 'e': mask ^= (1 << 1); break;
            case 'i': mask ^= (1 << 2); break;
            case 'o': mask ^= (1 << 3); break;
            case 'u': mask ^= (1 << 4); break;
        }

        if (first_occurrence[mask] != -1) {
            int length = (i + 1) - first_occurrence[mask];
            if (length > max_len) {
                max_len = length;
            }
        } else {
            first_occurrence[mask] = i + 1;
        }
    }

    return max_len;
}
// Test cases
int main() {
    char s1[] = "eleetminicoworoep";
    printf("Test 1: Input: %s, Output: %d\n", s1, findTheLongestSubstring(s1));

    char s2[] = "leetcodeisgreat";
    printf("Test 2: Input: %s, Output: %d\n", s2, findTheLongestSubstring(s2));

    char s3[] = "bcbcbc";
    printf("Test 3: Input: %s, Output: %d\n", s3, findTheLongestSubstring(s3));

    return 0;
}
