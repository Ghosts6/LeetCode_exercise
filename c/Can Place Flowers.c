#include <stdio.h>
#include <stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int count = 0; 

    for (int i = 0; i < flowerbedSize; ++i) {
        if (flowerbed[i] == 0) {
            int prev = (i == 0) ? 0 : flowerbed[i - 1];
            int next = (i == flowerbedSize - 1) ? 0 : flowerbed[i + 1];

            if (prev == 0 && next == 0) {
                flowerbed[i] = 1;
                count++;
                i++; 
            }
        }
    }
    
    return count >= n;
}

// test case
int main() {
    int flowerbed[] = {1, 0, 0, 0, 1};
    int n1 = 1;
    printf("can place %d flowers: %s\n", n1, canPlaceFlowers(flowerbed, 5, n1) ? "true" : "false"); 

    return 0;
}
