#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success) {
        std::sort(potions.begin(), potions.end());
        int m = potions.size();
        std::vector<int> result;
        
        for (int spell : spells) {
            long long min_potion_strength = (success + spell - 1) / spell;
            int index = std::lower_bound(potions.begin(), potions.end(), min_potion_strength) - potions.begin();
            result.push_back(m - index);
        }
        
        return result;
    }
};
// Test cases
int main() {
    Solution solution;
    std::vector<int> spells = {10, 20, 30};
    std::vector<int> potions = {1, 2, 3, 4, 5};
    long long success = 20;
    std::vector<int> result = solution.successfulPairs(spells, potions, success);
    
    for (int count : result) {
        std::cout << count << " ";
    }
    std::cout << std::endl;
    return 0;
}