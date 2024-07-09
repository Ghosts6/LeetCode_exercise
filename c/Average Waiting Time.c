#include <stdio.h>

double averageWaitingTime(int** customers, int customersSize, int* customersColSize) {
    int n = customersSize;
    double time_waiting = 0.0;
    int current_time = 0;

    for (int i = 0; i < n; ++i) {
        int arrival_time = customers[i][0];
        int preparation_time = customers[i][1];
        
        int start_cook = arrival_time > current_time ? arrival_time : current_time;
        int end_time = start_cook + preparation_time;
        
        time_waiting += end_time - arrival_time;
        current_time = end_time;
    }

    return time_waiting / n;
}

//  test case
int main() {
    int customersSize = 4;
    int customersColSize = 2;
    int customers[4][2] = {{1, 2}, {2, 5}, {4, 3}, {5, 2}};

    int* customersPtr[customersSize];
    for (int i = 0; i < customersSize; ++i) {
        customersPtr[i] = customers[i];
    }

    double result = averageWaitingTime(customersPtr, customersSize, &customersColSize);
    printf("Average Waiting Time: %.5f\n", result);
    
    return 0;
}


