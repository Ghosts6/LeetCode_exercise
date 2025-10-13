#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isAnagram(char *a, char *b);
char **removeAnagrams(char **words, int wordsSize, int *returnSize);

int main() {
    char *words[] = {"abba", "baba", "bbaa", "cd", "cd"};
    int wordsSize = 5, returnSize;
    char **ans = removeAnagrams(words, wordsSize, &returnSize);
    for (int i = 0; i < returnSize; i++) printf("%s ", ans[i]);
    printf("\n");
    free(ans);
    return 0;
}

int isAnagram(char *a, char *b) {
    if (strlen(a) != strlen(b)) return 0;
    int count[26] = {0};
    for (int i = 0; a[i]; i++) count[a[i] - 'a']++;
    for (int i = 0; b[i]; i++) count[b[i] - 'a']--;
    for (int i = 0; i < 26; i++) if (count[i]) return 0;
    return 1;
}

char **removeAnagrams(char **words, int wordsSize, int *returnSize) {
    char **res = malloc(wordsSize * sizeof(char *));
    int k = 0;
    res[k++] = words[0];
    for (int i = 1; i < wordsSize; i++) {
        if (!isAnagram(words[i], words[i - 1])) res[k++] = words[i];
    }
    *returnSize = k;
    return res;
}
