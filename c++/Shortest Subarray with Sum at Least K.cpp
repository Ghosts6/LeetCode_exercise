#include <iostream>
#include <vector>
#include <deque>
#include <climits>

class Solution {
public:
    int shortestSubarray(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<long long> prefixSum(n + 1, 0); 
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        std::deque<int> dq; 
        int minLength = INT_MAX;

        for (int i = 0; i <= n; ++i) {
            while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k) {
                minLength = std::min(minLength, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }
        return (minLength == INT_MAX) ? -1 : minLength;
    }
};
// Test cases
int main() {
    Solution solution;

    // Case 1
    std::vector<int> nums1 = {1};
    int k1 = 1;
    std::cout << "Test Case 1 Output: " << solution.shortestSubarray(nums1, k1) << std::endl;

    // Case 2
    std::vector<int> nums2 = {1, 2};
    int k2 = 4;
    std::cout << "Test Case 2 Output: " << solution.shortestSubarray(nums2, k2) << std::endl;

    // Case 3
    std::vector<int> nums3 = {2, -1, 2};
    int k3 = 3;
    std::cout << "Test Case 3 Output: " << solution.shortestSubarray(nums3, k3) << std::endl;

    return 0;
}
