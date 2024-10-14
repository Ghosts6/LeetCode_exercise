#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

class Solution {
public:
    long long maxKelements(std::vector<int>& nums, int k) {
        std::priority_queue<int> maxHeap(nums.begin(), nums.end());
        
        long score = 0;

        for (int i = 0; i < k; ++i) {
            long maxElement = maxHeap.top();
            maxHeap.pop();
            score += maxElement;

            long newValue = std::ceil(maxElement / 3.0);

            maxHeap.push(newValue);
        }
        
        return score;
    }
};

// Test cases
int main() {
    Solution solution;
    
    // case 1
    std::vector<int> nums1 = {10, 10, 10, 10, 10};
    int k1 = 5;
    std::cout << "Output for nums = {10, 10, 10, 10, 10}, k = 5: " << solution.maxKelements(nums1, k1) << std::endl;  // Expected output: 50
    
    // case 2
    std::vector<int> nums2 = {1, 10, 3, 3, 3};
    int k2 = 3;
    std::cout << "Output for nums = {1, 10, 3, 3, 3}, k = 3: " << solution.maxKelements(nums2, k2) << std::endl;  // Expected output: 17
    
    return 0;
}
