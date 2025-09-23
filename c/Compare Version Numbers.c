#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compareVersion(const char *version1, const char *version2) {
    int i = 0, j = 0;
    int n1 = strlen(version1);
    int n2 = strlen(version2);

    while (i < n1 || j < n2) {
        long num1 = 0, num2 = 0;

        while (i < n1 && version1[i] != '.') {
            num1 = num1 * 10 + (version1[i] - '0');
            i++;
        }

        while (j < n2 && version2[j] != '.') {
            num2 = num2 * 10 + (version2[j] - '0');
            j++;
        }

        if (num1 < num2) return -1;
        if (num1 > num2) return 1;

        if (i < n1 && version1[i] == '.') i++;
        if (j < n2 && version2[j] == '.') j++;
    }

    return 0;
}

// Test cases
int main() {
    // case 1
    char version1[] = "1.2", version2[] = "1.10";
    int result = compareVersion(version1, version2);
    printf("Result of test case for %s and %s : %d\n", version1, version2, result); // Expected -1

    // case 2
    char version1_2[] = "1.01", version2_2[] = "1.001";
    int result2 = compareVersion(version1_2, version2_2);
    printf("Result of test case for %s and %s : %d\n", version1_2, version2_2, result2); // Expected 0

    // case 3
    char version1_3[] = "1.0", version2_3[] = "1.0.0.0";
    int result3 = compareVersion(version1_3, version2_3);
    printf("Result of test case for %s and %s : %d\n", version1_3, version2_3, result3); // Expected 0

    return 0;
}
