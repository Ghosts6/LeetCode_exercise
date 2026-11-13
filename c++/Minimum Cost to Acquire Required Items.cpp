#include <iostream>

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
	long long count = 0;
        
	if (cost1 + cost2 > costBoth) {
		long long sim = need1 < need2 ? need1 : need2;
		count += costBoth * sim;
		need1 -= sim;
		need2 -= sim;
	}

	if (cost1 <= costBoth && need1 > 0) {
            count += 1LL * cost1 * need1;
	} else if(cost1 > costBoth && need1 > 0) {
            count += 1LL * costBoth * need1;
	}

	if (cost2 <= costBoth && need2 > 0) {
            count += 1LL * cost2 * need2;
	} else if(cost2 > costBoth && need2 > 0) {
            count += 1LL * costBoth * need2;
	}

	return count;
    }
};

// Test cases
int main() {
    Solution sol;

    // case 1
    int case1[] = {3, 2, 1, 3, 2}; 
    std::cout<< "Result of test case 1 : " << sol.minimumCost(case1[0], case1[1], case1[2], case1[3], case1[4]) << std::endl; // Expected: 3

    // case 2
    int case2[] = {5, 4, 15, 2, 3};
    std::cout<< "Result of test case 2 : " << sol.minimumCost(case2[0], case2[1], case2[2], case2[3], case2[4]) << std::endl; // Expected: 22

    // case 3
    int case3[] = {5, 4, 15, 0, 0};
    std::cout<< "Result of test case 3 : " << sol.minimumCost(case3[0], case3[1], case3[2], case3[3], case3[4]) << std::endl; // Expected: 0
    return 0;
}
