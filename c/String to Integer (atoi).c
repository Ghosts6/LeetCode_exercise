#include <stdio.h>
#include <limits.h>
#include <ctype.h>

int myAtoi(char* s);

int main() {
  // case 1
  char s[] = "42";
  printf("Result of test case 1 : %d\n", myAtoi(s); // Expected 42
  
  // case 2
  char s2[] = " -042";
  printf("Result of test case 2 : %d\n", myAtoi(s2); // Expected -42

  // case 3
  char s3[] = "1337c0d3";
  printf("Result of test case 3 : %d\n", myAtoi(s3); // Expected 1337
  
  return 0;
}

int myAtoi(char* s) {
    int i = 0;
    int sign = 1;
    long result = 0;

    // 1. Skip leading whitespaces
    while (isspace(s[i])) {
        i++;
    }

    // 2. Check for optional '+' or '-'
    if (s[i] == '+' || s[i] == '-') {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // 3. Convert digits to integer
    while (isdigit(s[i])) {
        int digit = s[i] - '0';

        // Check overflow BEFORE multiplying by 10
        if (sign == 1 && (result > (INT_MAX - digit) / 10)) {
            return INT_MAX;
        }
        if (sign == -1 && (-result < (INT_MIN + digit) / 10)) {
            return INT_MIN;
        }

        result = result * 10 + digit;
        i++;
    }

    return (int)(result * sign);
}
