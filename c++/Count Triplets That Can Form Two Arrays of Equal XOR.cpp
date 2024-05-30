#include <iostream>
#include <vector>

class Solution {
public:
    int countTriplets(std::vector<int>& arr) {
        int n = arr.size();
        std::vector<int> prefixXor(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixXor[i + 1] = prefixXor[i] ^ arr[i];
        }
        
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int k = i + 1; k < n; ++k) {
                if (prefixXor[i] == prefixXor[k + 1]) {
                    count += (k - i);
                }
            }
        }
        
        return count;
    }
};
//  test cases
int main() {
    Solution solution;

    std::vector<int> arr1 = {2, 3, 1, 6, 7};
    std::cout << "Test case 1 result: " << solution.countTriplets(arr1) << " (Expected: 4)" << std::endl;

    std::vector<int> arr2 = {1, 1, 1, 1, 1};
    std::cout << "Test case 2 result: " << solution.countTriplets(arr2) << " (Expected: 10)" << std::endl;


    return 0;
}
