#include <iostream>
#include <vector>
#include <algorithm> 

class Solution {
public:
    long long dividePlayers(std::vector<int>& skill) {
        int n = skill.size();

        std::sort(skill.begin(), skill.end());
        
        long long total_chemistry = 0;
        int target_sum = skill[0] + skill[n - 1];

        for (int i = 0, j = n - 1; i < j; ++i, --j) {
            int current_sum = skill[i] + skill[j];

            if (current_sum != target_sum) {
                return -1; 
            }
            
            total_chemistry += static_cast<long long>(skill[i]) * skill[j];
        }
        
        return total_chemistry;
    }
};

// Test cases
int main() {
    Solution sol;

    // case 1
    std::vector<int> skill1 = {3, 2, 5, 1, 3, 4};
    std::cout << "Test case 1: " << sol.dividePlayers(skill1) << std::endl;  // Expected output: 22

    // case 2
    std::vector<int> skill2 = {3, 4};
    std::cout << "Test case 2: " << sol.dividePlayers(skill2) << std::endl;  // Expected output: 12

    // case 3
    std::vector<int> skill3 = {1, 2, 3, 4};
    std::cout << "Test case 3: " << sol.dividePlayers(skill3) << std::endl;  // Expected output: -1

    return 0;
}
