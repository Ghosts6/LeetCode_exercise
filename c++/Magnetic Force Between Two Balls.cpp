#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool canPlaceBalls(const std::vector<int>& position, int m, int minForce) {
        int count = 1;
        int last_position = position[0];

        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - last_position >= minForce) {
                count++;
                last_position = position[i];
                if (count == m) {
                    return true;
                }
            }
        }

        return false;
    }

    int maxDistance(std::vector<int>& position, int m) {
        std::sort(position.begin(), position.end());

        int left = 1; 
        int right = position.back() - position.front(); 

        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (canPlaceBalls(position, m, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
};

// test case
int main() {
    Solution solution;

    std::vector<int> position = {1, 2, 3, 4, 7};
    int m = 3;

    int result = solution.maxDistance(position, m);

    std::cout << "result :" << result << std::endl; 

    return 0;
}