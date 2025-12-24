#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int minimumBoxes(std::vector<int>& apple, std::vector<int>& capacity) {
        // Calculate total number of apples
        long long totalApples = 0;
        for (int a : apple) {
            totalApples += a;
        }

        // Sort capacities in descending order to use the largest boxes first
        std::sort(capacity.begin(), capacity.end(), std::greater<int>());

        int boxesUsed = 0;
        for (int cap : capacity) {
            totalApples -= cap;
            boxesUsed++;
            
            // If totalApples drops to 0 or less, we have enough capacity
            if (totalApples <= 0) {
                return boxesUsed;
            }
        }

        return boxesUsed;
    }
};

// Test cases
int main() {
    Solution sol;

    // case 1
    std::vector<int> apple1 = {1, 3, 2};
    std::vector<int> capacity1 = {4, 3, 1, 5, 2};
    std::cout << "Result of test case 1 : " << sol.minimumBoxes(apple1, capacity1) << std::endl; // Expected: 2

    // case 2
    std::vector<int> apple2 = {5, 5, 5};
    std::vector<int> capacity2 = {2, 4, 2, 7};
    std::cout << "Result of test case 2 : " << sol.minimumBoxes(apple2, capacity2) << std::endl; // Expected: 4 

    return 0; 
}
