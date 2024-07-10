#include <stdio.h>
#include <string.h>

int minOperations(char **logs, int logsSize) {
    int depth = 0;
    for (int i = 0; i < logsSize; ++i) {
        if (strcmp(logs[i], "../") == 0) {
            if (depth > 0) {
                depth--;
            }
        } else if (strcmp(logs[i], "./") != 0) {
            depth++;
        }
    }
    return depth;
}

int main() {
    char *logs1[] = {"d1/", "d2/", "../", "d21/", "./"};
    int logsSize1 = sizeof(logs1) / sizeof(logs1[0]);
    printf("Minimum operations to return to main folder: %d\n", minOperations(logs1, logsSize1));

    char *logs2[] = {"d1/", "d2/", "./", "d3/", "../", "d31/"};
    int logsSize2 = sizeof(logs2) / sizeof(logs2[0]);
    printf("Minimum operations to return to main folder: %d\n", minOperations(logs2, logsSize2));

    return 0;
}