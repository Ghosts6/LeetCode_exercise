#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> lexicalOrder(int n) {
        std::vector<int> result;
        int current = 1;
        for (int i = 0; i < n; ++i) {
            result.push_back(current);
            if (current * 10 <= n) {
                current *= 10;
            } else {
                if (current >= n) {
                    current /= 10;
                }
                current++;
                while (current % 10 == 0) {
                    current /= 10;
                }
            }
        }
        return result;
    }
};

// Test cases
int main() {
    Solution solver;

    int n1 = 13;
    std::vector<int> result1 = solver.Solution(n1);
    std::cout << "Lexicographical order for n = " << n1 << ": ";
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // case 2
    int n2 = 2;
    std::vector<int> result2 = solver.Solution(n2);
    std::cout << "Lexicographical order for n = " << n2 << ": ";
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    //  case 3
    int n3 = 100;
    std::vector<int> result3 = solver.Solution(n3);
    std::cout << "Lexicographical order for n = " << n3 << ": ";
    for (int num : result3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
