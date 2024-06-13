#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize) {
    if (seatsSize != studentsSize) {
        return -1; 
    }

    qsort(seats, seatsSize, sizeof(int), compare);
    qsort(students, studentsSize, sizeof(int), compare);

    int min_moves = 0;

    for (int i = 0; i < seatsSize; ++i) {
        min_moves += abs(seats[i] - students[i]);
    }

    return min_moves;
}

int main() {
    int seats[] = {4, 1, 5, 9};
    int students[] = {1, 3, 2, 6};
    int seatsSize = sizeof(seats) / sizeof(seats[0]);
    int studentsSize = sizeof(students) / sizeof(students[0]);

    int result = minMovesToSeat(seats, seatsSize, students, studentsSize);
    printf("minimum moves to seat students: %d\n", result);

    return 0;
}
