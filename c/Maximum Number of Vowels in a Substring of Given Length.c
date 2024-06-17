#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int maxVowels(char *s, int k) {
    int max_vowels = 0, current_vowels = 0;
    int n = strlen(s);
    
    for (int i = 0; i < k; i++) {
        if (isVowel(s[i])) {
            current_vowels++;
        }
    }
    
    max_vowels = current_vowels;
    
    for (int i = k; i < n; i++) {
        if (isVowel(s[i])) {
            current_vowels++;
        }
        if (isVowel(s[i - k])) {
            current_vowels--;
        }
        if (current_vowels > max_vowels) {
            max_vowels = current_vowels;
        }
    }
    
    return max_vowels;
}

// test case
int main() {
    char s[] = "abciiidef";
    int k = 3;
    int result = maxVowels(s, k);
    printf("maximum number of vowels  %d: %d\n", k, result);  
    
    return 0;
}
