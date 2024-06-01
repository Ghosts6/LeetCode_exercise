#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int scoreOfString(char* s) {
    int score = 0;
    for (int i = 1; s[i] != '\0'; ++i) {
        score += abs(s[i] - s[i - 1]);
    }
    return score;
}
//  test case
int main() {
    char s[] = "abcd";
    int score = scoreOfString(s);
    printf("score: %d\n", score);
    return 0;
}
