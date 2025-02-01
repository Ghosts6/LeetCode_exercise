// time limit error for large test cases
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

class Solution {
public:
    std::vector<int> lexicographicallySmallestArray(std::vector<int>& nums, int limit) {
        int n = nums.size();
        std::vector<int> parent(n);
        for (int i = 0; i < n; ++i) parent[i] = i;

        auto find = [&](int x) {
            while (x != parent[x]) {
                parent[x] = parent[parent[x]]; 
                x = parent[x];
            }
            return x;
        };

        auto unite = [&](int x, int y) {
            x = find(x);
            y = find(y);
            if (x != y) parent[x] = y;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (std::abs(nums[j] - nums[i]) <= limit) {
                    unite(i, j);
                }
            }
        }

        std::map<int, std::vector<int>> groups;
        for (int i = 0; i < n; ++i) {
            groups[find(i)].push_back(i);
        }

        for (auto& group : groups) {
            std::vector<int>& indices = group.second;
            std::vector<int> values;
            for (int idx : indices) {
                values.push_back(nums[idx]);
            }
            std::sort(indices.begin(), indices.end());
            std::sort(values.begin(), values.end());
            for (int i = 0; i < indices.size(); ++i) {
                nums[indices[i]] = values[i];
            }
        }

        return nums;
    }
};
// Test cases
int main() {
    Solution solution;

    // Case 1
    std::vector<int> nums1 = {1, 5, 3, 9, 8};
    int limit1 = 2;
    std::vector<int> result1 = solution.lexicographicallySmallestArray(nums1, limit1);
    std::cout << "Test Case 1: ";
    for (int num : result1) {
        std::cout << num << " "; // Expected Output: [1,3,5,8,9]
    }
    std::cout << std::endl;

    // Case 2
    std::vector<int> nums2 = {1, 7, 6, 18, 2, 1};
    int limit2 = 3;
    std::vector<int> result2 = solution.lexicographicallySmallestArray(nums2, limit2);
    std::cout << "Test Case 2: ";
    for (int num : result2) {
        std::cout << num << " "; // Expected Output: [1,6,7,18,1,2]] 
    }
    std::cout << std::endl;

    // Case 3
    std::vector<int> nums3 = {1, 7, 28, 19, 10};
    int limit3 = 3;
    std::vector<int> result3 = solution.lexicographicallySmallestArray(nums3, limit3);
    std::cout << "Test Case 3: ";
    for (int num : result3) {
        std::cout << num << " "; // Expected Output: [1,7,28,19,10]
    }
    std::cout << std::endl;

    return 0;
}
