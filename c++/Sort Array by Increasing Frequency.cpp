#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> frequencySort(std::vector<int>& nums) {
        std::unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        std::sort(nums.begin(), nums.end(), [&freq](int a, int b) {
            if (freq[a] != freq[b]) {
                return freq[a] < freq[b];
            }
            return a > b;
        });
        
        return nums;
    }
};
//  test case
int main() {
    Solution sorter;
    std::vector<int> nums = {1, 1, 2, 2, 2, 3};
    std::vector<int> sortedNums = sorter.frequencySort(nums);
    
    std::cout << "sorted array: ";
    for (int num : sortedNums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
