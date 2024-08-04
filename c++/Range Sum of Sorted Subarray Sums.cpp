#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// require std
using std::vector;
using std::priority_queue;
using std::pair;
using std::greater;
using std::cout;
using std::endl;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1e9 + 7;
        vector<int> prefixSums(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            prefixSums[i + 1] = (prefixSums[i] + nums[i]) % MOD;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (int i = 0; i < n; ++i) {
            minHeap.push({prefixSums[i + 1] - prefixSums[i], i + 1});
        }
        
        long long result = 0;
        for (int k = 1; k <= right; ++k) {
            auto [currentSum, endIndex] = minHeap.top();
            minHeap.pop();

            if (k >= left) {
                result = (result + currentSum) % MOD;
            }
            
            if (endIndex < n) {
                minHeap.push({(currentSum + nums[endIndex]) % MOD, endIndex + 1});
            }
        }
        
        return result;
    }
};
//  test case
int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};
    int n = nums.size();
    int left = 1;
    int right = 5;
    int result = solution.rangeSum(nums, n, left, right);
    cout << "Result: " << result << endl;  
    return 0;
}

