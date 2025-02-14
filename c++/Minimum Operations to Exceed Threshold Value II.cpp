#include <iostream>
#include <vector>
#include <queue>

class Solution {
    public:
        int minOperations(std::vector<int>& nums, int k) {
            std::priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>> minHeap(nums.begin(), nums.end());
            int operations = 0;
            
            while (minHeap.size() > 1 && minHeap.top() < k) {
                int64_t x = minHeap.top(); minHeap.pop();
                int64_t y = minHeap.top(); minHeap.pop();
                minHeap.push(x * 2 + y);
                operations++;
            }
            
            return operations;
        }
};

// Test cases
int main() {
    Solution solution;
    // case 1
    std::vector<int> nums1 = {2, 11, 10, 1, 3};
    int k1 = 10;
    std::cout<<"result of test case 1:"<<solution.minOperations(nums1, k1)<<std::endl; // Expected Output: 2
    // case 2
    std::vector<int> nums2 = {1, 1, 2, 4, 9};
    int k2 =20;
    std::cout<<"result of test case 2:"<<solution.minOperations(nums2, k2)<<std::endl; // Expected Output: 4

    return 0;
}