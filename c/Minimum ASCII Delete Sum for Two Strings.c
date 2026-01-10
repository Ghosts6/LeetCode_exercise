#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minimumDeleteSum(char* s1, char* s2);

//  Test cases
int main() {
    // case 1
    char s1_1[] = "sea";
    char s1_2[] = "eat";

    printf("Result of test case 1 : %d\n", minimumDeleteSum(s1_1, s1_2)); // Expected: 231
    // case 2
    char s2_1[] = "delete";
    char s2_2[] = "leet";

    printf("Result of test case 2 : %d\n", minimumDeleteSum(s2_1, s2_2)); // Expected: 403
    return 0;
}

int minimumDeleteSum(char* s1, char* s2) {
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    int* dp = (int*)malloc((n2 + 1) * sizeof(int));

    dp[0] = 0;
    for (int j = 1; j <= n2; j++) {
        dp[j] = dp[j - 1] + (int)s2[j - 1];
    }

    for (int i = 1; i <= n1; i++) {
        int prev = dp[0]; // Stores the value of dp[i-1][j-1]
        dp[0] += (int)s1[i - 1]; // Base case empty s2
        
        for (int j = 1; j <= n2; j++) {
            int temp = dp[j];
            if (s1[i - 1] == s2[j - 1]) {
                // Characters match
                dp[j] = prev;
            } else {
                dp[j] = MIN(dp[j] + (int)s1[i - 1], dp[j - 1] + (int)s2[j - 1]);
            }
            prev = temp;
        }
    }

    int result = dp[n2];
    free(dp);
    return result;
}
