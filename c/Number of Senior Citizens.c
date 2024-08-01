#include <stdio.h>
#include <stdlib.h>

int countSeniors(char** details, int detailsSize) {
    int count = 0;
    for (int i = 0; i < detailsSize; i++) {
        char ageStr[3] = {details[i][11], details[i][12], '\0'};

        int age = atoi(ageStr);

        if (age > 60) {
            count++;
        }
    }
    return count;
}
//  test case
int main() {
    char* details[] = {
        "1234567890M65A1",
        "0987654321F45B2",
        "1122334455M61C3",
        "5566778899F62D4"
    };
    int detailsSize = sizeof(details) / sizeof(details[0]);
    
    int result = countSeniors(details, detailsSize);
    printf("number of passengers older than 60: %d\n", result);
    
    return 0;
}
