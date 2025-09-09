#include <stdio.h>

#define MOD 1000000007

int peopleAwareOfSecret(int n, int delay, int forget);

int main() {
    // Test cases

    // case 1
    int n1 = 6, delay1 = 2, forget1 = 4;
    int result1 = peopleAwareOfSecret(n1, delay1, forget1);
    printf("Result of test case 1 : %d\n", result1);

    // case 2
    int n2 = 4, delay2 = 1, forget2 = 3;
    int result2 = peopleAwareOfSecret(n2, delay2, forget2);
    printf("Result of test case 2 : %d\n", result2);

    return 0;
}

int peopleAwareOfSecret(int n, int delay, int forget) {
    long dp[n + 1];      
    long share[n + 2];   
    for (int i = 0; i <= n; i++) {
        dp[i] = 0;
        share[i] = 0;
    }

    dp[1] = 1;  
    share[1 + delay] = 1;    
    if (1 + forget <= n) {
        share[1 + forget] = (share[1 + forget] - 1 + MOD) % MOD;
    }

    long curShare = 0; 
    for (int i = 2; i <= n; i++) {
        curShare = (curShare + share[i]) % MOD; 
        dp[i] = curShare;

        if (i + delay <= n) {
            share[i + delay] = (share[i + delay] + dp[i]) % MOD;
        }
        if (i + forget <= n) {
            share[i + forget] = (share[i + forget] - dp[i] + MOD) % MOD;
        }
    }

    // Count how many still remember 
    long ans = 0;
    for (int i = n - forget + 1; i <= n; i++) {
        if (i >= 1) {
            ans = (ans + dp[i]) % MOD;
        }
    }

    return (int)ans;
}
