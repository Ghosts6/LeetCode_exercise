#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countDigits(int num) {
        int count = 0;
        int originalNum = num;
        
        while (num > 0) {
            int digit = num % 10;
            num /= 10;
            
            // Avoid division by zero
            if (digit != 0 && originalNum % digit == 0) {
                count++;
            }
        }
        
        return count;
    }
};
// Test cases
int main() {
    Solution sol;
    cout << sol.countDigits(7) << endl;   // Output: 1
    cout << sol.countDigits(121) << endl; // Output: 2
    cout << sol.countDigits(1248) << endl; // Output: 4
    return 0;
}
