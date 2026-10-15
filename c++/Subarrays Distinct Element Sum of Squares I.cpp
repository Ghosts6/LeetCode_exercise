#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> freq;
            int distinct = 0;

            for (int j = i; j < n; j++) {
                if (freq[nums[j]] == 0) {
                    distinct++;
                }

                freq[nums[j]]++;
                result += distinct * distinct;
            }
        }

        return result;
    }
};

// Test cases
int main() {
    Solution solution;
    // case 1
    vector<int> nums1 = {1, 2, 1};
    cout << "Result of test case 1 : " << solution.sumCounts(nums1) << endl; // 15
    
    // case 2
    vector<int> nums2 = {1, 1};
    cout << "Result of test case 2 : " << solution.sumCounts(nums2) << endl; // 3

    return 0;
}

