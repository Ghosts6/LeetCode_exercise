#include <iostream>
#include <vector>
#include <stack>
#include <climits>

class Solution {
public:
    int mctFromLeafValues(std::vector<int>& arr) {
        std::stack<int> s;
        int result = 0;
        
        for (int i = 0; i < arr.size(); ++i) {
            while (!s.empty() && arr[i] > s.top()) {
                int mid = s.top();
                s.pop();

                int left = s.empty() ? INT_MAX : s.top();
                int right = arr[i];
                
                result += mid * std::min(left, right);
            }
            s.push(arr[i]);
        }

        while (s.size() > 1) {
            int mid = s.top();
            s.pop();
            result += mid * s.top();
        }
        
        return result;
    }
};
// Test cases
int main() {
    Solution solution;
    // case 1
    std::vector<int> arr1 = {6, 2, 4};
    std::cout << "Output for [6, 2, 4]: " << solution.mctFromLeafValues(arr1) << std::endl;
    
    //  case 2
    std::vector<int> arr2 = {4, 11};
    std::cout << "Output for [4, 11]: " << solution.mctFromLeafValues(arr2) << std::endl;
    
    return 0;
}
