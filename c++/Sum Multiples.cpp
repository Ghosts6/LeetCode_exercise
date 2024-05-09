#include <iostream>

class Solution {
public:
    int sumOfMultiples(int n) {
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
                sum += i;
            }
        }
        return sum;
    }
};
//  test case
int main() {
    Solution solution;
    int n = 20;
    int sum = solution.sumOfMultiples(n);
    std::cout << "result of test case :"<<sum<< std::endl;
    return 0;
}