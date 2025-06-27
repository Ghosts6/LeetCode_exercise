#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isAnagram(const char *s, const char *t) {
    if (strlen(s) != strlen(t)) return false;

    int count[26] = {0};

    for (int i = 0; s[i]; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) return false;
    }

    return true;
}

// Test cases
int main() {
    // case 1
    const char *test1_s = "anagram";
    const char *test1_t = "nagaram";
    printf("Test 1: %s\n", isAnagram(test1_s, test1_t) ? "true" : "false"); // Expected: true

    const char *test2_s = "rat";
    const char *test2_t = "car";
    printf("Test 2: %s\n", isAnagram(test2_s, test2_t) ? "true" : "false"); // Expected: false

    return 0;
}

