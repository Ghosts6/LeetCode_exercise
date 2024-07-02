#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> count1, count2;
        for (int num : nums1) {
            count1[num]++;
        }
        for (int num : nums2) {
            count2[num]++;
        }
        
        std::vector<int> intersection;
        for (auto& [num, count] : count1) {
            if (count2.find(num) != count2.end()) {
                int min_count = std::min(count, count2[num]);
                for (int i = 0; i < min_count; ++i) {
                    intersection.push_back(num);
                }
            }
        }
        return intersection;
    }
};
//  test case
int main() {
    Solution solution;
    std::vector<int> nums1 = {1, 2, 2, 1};
    std::vector<int> nums2 = {2, 2};
    
    std::vector<int> result = solution.intersect(nums1, nums2);
    std::cout << "result: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}