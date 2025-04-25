#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
public:
    long long countInterestingSubarrays(std::vector<int>& nums, int modulo, int k) {
        std::unordered_map<int, long long> freq;
        freq[0] = 1;
        long long res = 0, cnt = 0;

        for (int num : nums) {
            cnt += (num % modulo == k);
            int mod = ((cnt - k) % modulo + modulo) % modulo;
            res += freq[mod];
            freq[cnt % modulo]++;
        }

        return res;
    }
};

// Test cases
int main() {
    Solution obj;

    std::vector<int> nums1 = {3, 2, 4};
    int modulo1 = 2, k1 = 1;
    std::cout << "result of test case 1: " << obj.countInterestingSubarrays(nums1, modulo1, k1) << std::endl; // Expected Output: 3

    std::vector<int> nums2 = {3, 1, 9, 6};
    int modulo2 = 3, k2 = 0;
    std::cout << "result of test case 2: " << obj.countInterestingSubarrays(nums2, modulo2, k2) << std::endl; // Expected Output: 2

    return 0;
}
