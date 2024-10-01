#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool canArrange(std::vector<int>& arr, int k) {
        std::unordered_map<int, int> remainderCount;

        for (int num : arr) {
            int remainder = num % k;
            if (remainder < 0) remainder += k; 
            remainderCount[remainder]++;
        }

        for (int num : arr) {
            int remainder = num % k;
            if (remainder < 0) remainder += k; 

            if (remainder == 0) {
                if (remainderCount[remainder] % 2 != 0)
                    return false;
            } else {
                int complement = k - remainder;
                if (remainderCount[remainder] != remainderCount[complement])
                    return false;
            }
        }
        return true;
    }
};

// Test cases 
int main() {
    Solution solution;

    // Case 1
    std::vector<int> arr1 = {1, 2, 3, 4, 5, 10, 6, 7, 8, 9};
    int k1 = 5;
    std::cout << "Test Case 1: " << (solution.canArrange(arr1, k1) ? "true" : "false") << std::endl;

    // Case 2
    std::vector<int> arr2 = {1, 2, 3, 4, 5, 6};
    int k2 = 7;
    std::cout << "Test Case 2: " << (solution.canArrange(arr2, k2) ? "true" : "false") << std::endl;

    // Case 3 
    std::vector<int> arr3 = {1, 2, 3, 4, 5, 6, 7, 8};
    int k3 = 4;
    std::cout << "Test Case 3: " << (solution.canArrange(arr3, k3) ? "true" : "false") << std::endl;

    return 0;
}
