#include <iostream>

class Solution {
	public:
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
};
// Test case
int main() {
	Solution sol;
	// case 1
	int numBottles = 9, numExchange = 3;
	std::cout << "Result of test case 1: " << sol.numWaterBottles(numBottles, numExchange) << std::endl; // Expected 13

	// case 2
	int numBottles2 = 15, numExchange2 = 4;
	std::cout << "Result of test case 2: " << sol.numWaterBottles(numBottles2, numExchange2) << std::endl; // Expected 19

	return 0;
}
