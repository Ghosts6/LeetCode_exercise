#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// lsd radix sort with base 256
static void radixSort(int* a, int n) {
    int* buf = malloc(n * sizeof(int));
    int* src = a;
    int* dst = buf;

    for (int shift = 0; shift < 32; shift += 8) {
        int count[257] = {0};
        for (int i = 0; i < n; i++) count[((src[i] >> shift) & 0xFF) + 1]++;
        for (int i = 0; i < 256; i++) count[i + 1] += count[i];
        for (int i = 0; i < n; i++) dst[count[(src[i] >> shift) & 0xFF]++] = src[i];
        int* tmp = src; src = dst; dst = tmp;
    }

    free(buf);
}

int minProcessingTime(int* processorTime, int processorTimeSize, int* tasks, int tasksSize) {
    radixSort(processorTime, processorTimeSize);
    radixSort(tasks, tasksSize);

    // Earliest processor takes the 4 longest tasks ...
    int result = 0;
    for (int i = 0; i < processorTimeSize; i++) {
        int finish = processorTime[i] + tasks[tasksSize - 1 - 4 * i];
        if (finish > result) result = finish;
    }
    return result;
}

// Test cases
int main(void) {
    // case 1
    int p1[] = {8, 10};
    int t1[] = {2, 2, 3, 1, 8, 7, 4, 5};
    printf("Test case 1: %d (expected ans 16)\n", minProcessingTime(p1, 2, t1, 8));

    // case 2
    int p2[] = {10, 20};
    int t2[] = {2, 3, 1, 2, 5, 8, 4, 3};
    printf("Test case 2: %d (expected ans 23)\n", minProcessingTime(p2, 2, t2, 8));
    
    //  case 3
    int p3[] = {0};
    int t3[] = {1, 1, 1, 1};
    printf("Edge case : %d (expected ans 1)\n", minProcessingTime(p3, 1, t3, 4));

    return 0;
}
