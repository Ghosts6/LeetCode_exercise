#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    std::vector<int> maxSubsequence(std::vector<int>& nums, int k) {
        using Pair = std::pair<int, int>; // {value, index}
        auto cmp = [](const Pair& a, const Pair& b) {
            return a.first > b.first; // Min-heap (smallest value on top)
        };
        std::priority_queue<Pair, std::vector<Pair>, decltype(cmp)> minHeap(cmp);
        
        for (int i = 0; i < nums.size(); ++i) {
            minHeap.emplace(nums[i], i);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        std::vector<Pair> topK;
        while (!minHeap.empty()) {
            topK.push_back(minHeap.top());
            minHeap.pop();
        }

        // Sort selected elements by their original index
        std::sort(topK.begin(), topK.end(), [](const Pair& a, const Pair& b) {
            return a.second < b.second;
        });

        std::vector<int> result;
        result.reserve(k);
        for (const auto& p : topK) {
            result.push_back(p.first);
        }

        return result;
    }
};

// Test cases
int main() {
    Solution solution;

    // Case 1
    {
        std::vector<int> nums = {3, 5, 2, 9, 1};
        int k = 3;
        std::vector<int> result = solution.maxSubsequence(nums, k);
        std::cout << "Case 1: ";
        for (int num : result) std::cout << num << " ";
        std::cout << std::endl;
    }

    // Case 2
    {
        std::vector<int> nums = {1, 2, 3, 4, 5};
        int k = 2;
        std::vector<int> result = solution.maxSubsequence(nums, k);
        std::cout << "Case 2: ";
        for (int num : result) std::cout << num << " ";
        std::cout << std::endl;
    }

    // Case 3
    {
        std::vector<int> nums = {50, -1, -100, 20, 30, 70};
        int k = 4;
        std::vector<int> result = solution.maxSubsequence(nums, k);
        std::cout << "Case 3: ";
        for (int num : result) std::cout << num << " ";
        std::cout << std::endl;
    }

    return 0;
}

