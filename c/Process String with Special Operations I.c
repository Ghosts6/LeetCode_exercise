#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// incomplete need a fix for test case 949
// heap buffer over flow and pointer 

char* processStr(char* s) {
    int n = strlen(s);

    long maxLen = 0, len = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') { if (len) len--; }
        else if (s[i] == '#') len *= 2;
        else if (s[i] != '%') len++;
        if (len > maxLen) maxLen = len;
    }

    int pad = n + 1;
    char* buf = malloc(pad + maxLen + 1);
    int head = pad, tail = pad;
    int reversed = 0;

    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == '%') {
            reversed ^= 1;
        } else if (c == '#') {
            int size = tail - head;
            memcpy(buf + tail, buf + head, size);
            tail += size;
        } else if (c == '*') {
            if (tail > head) {
                if (reversed) head++;
                else tail--;
            }
        } else if (reversed) {
            buf[--head] = c;
        } else {
            buf[tail++] = c;
        }
    }

    int size = tail - head;
    memmove(buf, buf + head, size);
    buf[size] = '\0';

    if (reversed) {
        for (int i = 0, j = size - 1; i < j; i++, j--) {
            char t = buf[i]; buf[i] = buf[j]; buf[j] = t;
        }
    }
    return buf;
}

// Test cases
int main(void) {
    const char* tests[][2] = {
	// test strings
        {"a#b%*", "ba"},
        {"z*#", ""},
        {"abc%", "cba"},
        {"ab%c", "bac"},
        {"ab%*", "b"},
    };
    int count = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < count; i++) {
        char* res = processStr((char*)tests[i][0]);
        
        printf("Test input \"%s\", Result: \"%s\" , Expected: \"%s\"\n", tests[i][0], res, tests[i][1]);
    }

    return 0;
}
