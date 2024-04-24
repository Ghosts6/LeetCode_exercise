#include <iostream>
#include <vector>

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        int t0 = 0, t1 = 1, t2 = 1;
        for (int i = 3; i <= n; ++i) {
            int tn = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = tn;
        }
        return t2;
    }
};

// test case
int main() {
    Solution sol;
    int n1 = 4;
    int result1 = sol.tribonacci(n1);
    std::cout<<"result :"<<result1<<std::endl;
    return 0;
}