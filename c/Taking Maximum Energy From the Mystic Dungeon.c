#include <stdio.h>

int maximumEnergy(int* energy, int energySize, int k);

int main() {
    // Test case 1
    int energy1[] = {5, 2, -10, -5, 1};
    int k1 = 3, size1 = 5;
    printf("Result of test case 1: %d\n", maximumEnergy(energy1, size1, k1)); // Expected: 3

    // Test case 2
    int energy2[] = {-2, -3, -1};
    int k2 = 2, size2 = 3;
    printf("Result of test case 2: %d\n", maximumEnergy(energy2, size2, k2)); // Expected: -1

    return 0;
}

int maximumEnergy(int* energy, int energySize, int k) {
    // Traverse backward to reuse computed results (dynamic programming)
    for (int i = energySize - 1; i >= 0; i--) {
        if (i + k < energySize) {
            energy[i] += energy[i + k];
        }
    }

    // Find the maximum energy achievable
    int maxEnergy = energy[0];
    for (int i = 1; i < energySize; i++) {
        if (energy[i] > maxEnergy) {
            maxEnergy = energy[i];
        }
    }

    return maxEnergy;
}

