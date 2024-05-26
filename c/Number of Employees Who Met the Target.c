#include <stdio.h>

int numberOfEmployeesWhoMetTarget(int* hours, int hoursSize, int target) {
    int count = 0;
    for (int i = 0; i < hoursSize; i++) {
        if (hours[i] >= target) {
            count++;
        }
    }
    return count;
}
//  test case
int main() {
    int hours[] = {5, 9, 3, 8, 7, 10};
    int target = 8;
    int hoursSize = sizeof(hours) / sizeof(hours[0]);
    int result = numberOfEmployeesWhoMetTarget(hours, hoursSize, target);
    printf("number of employees who worked at least %d hours: %d\n", target, result);
    return 0;
}
