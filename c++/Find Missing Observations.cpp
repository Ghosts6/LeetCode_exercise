#include <iostream>
#include <vector>
#include <numeric>

class Solution {
public:
    std::vector<int> missingRolls(std::vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int totalRolls = n + m;

        int totalSum = mean * totalRolls;

        int observedSum = std::accumulate(rolls.begin(), rolls.end(), 0);
 
        int missingSum = totalSum - observedSum;

        if (missingSum < n || missingSum > 6 * n) {
            return {};  
        }
 
        std::vector<int> result(n, 1);

        missingSum -= n;  

        for (int i = 0; i < n && missingSum > 0; ++i) {
            int add = std::min(5, missingSum);  
            result[i] += add;
            missingSum -= add;
        }
        
        return result;
    }
};
//  Test cases
int main() {
    Solution solution;

    // Case 1
    std::vector<int> rolls1 = {3, 2, 4, 3};
    int mean1 = 4, n1 = 2;
    std::vector<int> result1 = solution.missingRolls(rolls1, mean1, n1);
    std::cout << "Test Case 1 Result: ";
    for (int num : result1) std::cout << num << " ";
    std::cout << std::endl;

    //  Case 2
    std::vector<int> rolls2 = {1, 5, 6};
    int mean2 = 3, n2 = 4;
    std::vector<int> result2 = solution.missingRolls(rolls2, mean2, n2);
    std::cout << "Test Case 2 Result: ";
    for (int num : result2) std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}
