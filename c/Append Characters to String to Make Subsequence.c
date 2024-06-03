#include <stdio.h>
#include <string.h>

int appendCharacters(char* s, char* t) {
    int sLen = strlen(s);
    int tLen = strlen(t);
    int j = 0; 

    for (int i = 0; i < sLen; ++i) {
        if (j < tLen && s[i] == t[j]) {
            j++;
        }
    }
    
    return tLen - j;
}

int main() {

    char s1[] = "abc";
    char t1[] = "d";
    int result1 = appendCharacters(s1, t1);
    printf("Test Case 1: %d\n", result1); 

    char s2[] = "abcde";
    char t2[] = "ace";
    int result2 = appendCharacters(s2, t2);
    printf("Test Case 2: %d\n", result2);

    return 0;
}
