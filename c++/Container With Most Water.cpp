#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int maxWater = 0;
        int left = 0, right = height.size() - 1;

        while (left < right) {
            int h = std::min(height[left], height[right]);
            maxWater = std::max(maxWater, h * (right - left));
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};
//  test case
int main() {
    Solution sol;
    std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int max_water = sol.maxArea(height);
    std::cout << "max water: " << max_water << std::endl;
    return 0;
}
