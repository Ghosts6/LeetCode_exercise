#include <stdio.h>

int numWaterBottles(int numBottles, int numExchange) {
    int totalDrunk = numBottles;
    int emptyBottles = numBottles;

    while (emptyBottles >= numExchange) {
        int newBottles = emptyBottles / numExchange;
        emptyBottles = emptyBottles % numExchange + newBottles;
        totalDrunk += newBottles;
    }

    return totalDrunk;
}
//  test case
int main() {
    int numBottles = 9;
    int numExchange = 3;
    int result = numWaterBottles(numBottles, numExchange);
    printf("Result : %d\n", result);
    return 0;
}
