#include <stdio.h>

void reverseString(char* s, int sSize) {
    int left = 0;
    int right = sSize - 1;
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

//  test case
int main() {
    char s[] = "hello";
    int sSize = sizeof(s) / sizeof(s[0]) - 1;
    reverseString(s, sSize);
    printf("result : %s\n", s);
    return 0;
}
