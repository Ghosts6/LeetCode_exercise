#include <iostream>
#include <vector>

class Solution {
public:
    int findTheDistanceValue(std::vector<int>& arr1, std::vector<int>& arr2, int d) {
        int count = 0;

        for (int i = 0; i < arr1.size(); i++) {
            bool valid = true;

            for (int j = 0; j < arr2.size(); j++) {
                if (abs(arr1[i] - arr2[j]) <= d) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                count++;
            }
        }

        return count;
    }
};

// Test cases
int main() {
    Solution sol;

    // case 1
    std::vector<int> arr1_1 = {4, 5, 8};
    std::vector<int> arr2_1 = {10, 9, 1, 8};
    int d1 = 2;
    std::cout<< "Result of test case 1 : " << sol.findTheDistanceValue(arr1_1, arr2_1, d1) << std::endl; // Expected: 2

    // case 2
    std::vector<int> arr1_2 = {1, 4, 2, 3};
    std::vector<int> arr2_2 = {-4, -3, 6, 10, 20, 30};
    int d2 = 3;
    std::cout<< "Result of test case 2 : " << sol.findTheDistanceValue(arr1_2, arr2_2, d2) << std::endl; // Expected: 2

    // case 3
    std::vector<int> arr1_3 = {2, 1, 100, 3};
    std::vector<int> arr2_3 = {-5, -2, 10, -3, 7};
    int d3 = 6;
    std::cout<< "Result of test case 3 : " << sol.findTheDistanceValue(arr1_3, arr2_3, d3) << std::endl; // Expected: 1

    return 0;
}
