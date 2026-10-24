#include <stdio.h>
#include <string.h>

int countDaysTogether(char* arriveAlice, char* leaveAlice, char* arriveBob, char* leaveBob) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int aStart = 0, aEnd = 0, bStart = 0, bEnd = 0;

    for (int i = 0; i < 2; i++) {
        aStart = aStart * 10 + arriveAlice[i] - '0';
        aEnd = aEnd * 10 + leaveAlice[i] - '0';
        bStart = bStart * 10 + arriveBob[i] - '0';
        bEnd = bEnd * 10 + leaveBob[i] - '0';
    }

    int startAlice = 0, endAlice = 0, startBob = 0, endBob = 0;

    for (int i = 1; i < aStart; i++) startAlice += days[i - 1];
    for (int i = 1; i < aEnd; i++) endAlice += days[i - 1];
    for (int i = 1; i < bStart; i++) startBob += days[i - 1];
    for (int i = 1; i < bEnd; i++) endBob += days[i - 1];

    startAlice += (arriveAlice[3] - '0') * 10 + arriveAlice[4] - '0';
    endAlice += (leaveAlice[3] - '0') * 10 + leaveAlice[4] - '0';
    startBob += (arriveBob[3] - '0') * 10 + arriveBob[4] - '0';
    endBob += (leaveBob[3] - '0') * 10 + leaveBob[4] - '0';

    int start = startAlice > startBob ? startAlice : startBob;
    int end = endAlice < endBob ? endAlice : endBob;

    return end >= start ? end - start + 1 : 0;
}

// Test case
int main() {
    // case 1
    char arriveAlice1[] = "08-15";
    char leaveAlice1[] = "08-18";
    char arriveBob1[] = "08-16";
    char leaveBob1[] = "08-19";
    int result1 = countDaysTogether(arriveAlice1, leaveAlice1, arriveBob1, leaveBob1);

    printf("Result of test case 1: %d\n", result1); // Expected: 3

    // case 2
    char arriveAlice2[] = "10-01";
    char leaveAlice2[] = "10-31";
    char arriveBob2[] = "11-01";
    char leaveBob2[] = "12-31";
    int result2 = countDaysTogether(arriveAlice2, leaveAlice2, arriveBob2, leaveBob2);

    printf("Result of test case 2: %d\n", result2); // Expected: 0

    return 0;
}
