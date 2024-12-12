#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void heapify(int *heap, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] > heap[largest])
        largest = left;

    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        heapify(heap, n, largest);
    }
}

void buildMaxHeap(int *heap, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(heap, n, i);
}

int extractMax(int *heap, int *n) {
    if (*n <= 0)
        return 0;

    int root = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    heapify(heap, *n, 0);
    return root;
}

void insertHeap(int *heap, int *n, int value) {
    heap[*n] = value;
    (*n)++;
    for (int i = (*n) / 2 - 1; i >= 0; i--)
        heapify(heap, *n, i);
}

long long pickGifts(int *gifts, int giftsSize, int k) {
    int heap[giftsSize];
    int heapSize = giftsSize;
  
    for (int i = 0; i < giftsSize; i++) {
        heap[i] = gifts[i];
    }
    buildMaxHeap(heap, heapSize);

    for (int i = 0; i < k; i++) {
        int maxGift = extractMax(heap, &heapSize);
        int remainingGift = (int)floor(sqrt(maxGift));
        insertHeap(heap, &heapSize, remainingGift);
    }

    long long totalGifts = 0;
    for (int i = 0; i < heapSize; i++) {
        totalGifts += heap[i];
    }
    return totalGifts;
}

// Test cases
int main() {
    int gifts1[] = {25, 64, 9, 4, 100};
    int k1 = 4;
    printf("Output: %lld\n", pickGifts(gifts1, 5, k1)); // Expected Output: 29

    int gifts2[] = {1, 1, 1, 1};
    int k2 = 4;
    printf("Output: %lld\n", pickGifts(gifts2, 4, k2)); // Expected Output: 4

    return 0;
}
