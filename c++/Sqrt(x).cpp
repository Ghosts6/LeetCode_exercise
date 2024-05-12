#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1){ 
            return x;
        }
        int left = 1, right = x, ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid <= x / mid) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
// test case
int main() {
    Solution solution;
    int x = 8;
    int result = solution.mySqrt(x);
    std::cout << "square root of " << x << " is: " << result << std::endl;
    return 0;
}
