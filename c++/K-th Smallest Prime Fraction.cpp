#include <iostream>
#include <vector>
#include <utility>

class Solution {
public:
    std::vector<int> kthSmallestPrimeFraction(std::vector<int>& arr, int k) {
        int n = arr.size();
        double left = 0.0, right = 1.0;
        std::vector<int> ans(2, 0);
        while (left < right) {
            double mid = left + (right - left) / 2;
            int count = 0, p = 0, q = 0;
            double maxFraction = 0.0;
            
            for (int i = 0, j = 1; i < n - 1; ++i) {
                while (j < n && arr[i] > mid * arr[j]) ++j;
                if (j == n) break;
                
                count += n - j;
                if ((double)arr[i] / arr[j] > maxFraction) {
                    maxFraction = (double)arr[i] / arr[j];
                    p = arr[i];
                    q = arr[j];
                }
            }
            if (count == k)
                return {p, q};
            else if (count < k)
                left = mid;
            else
                right = mid;
        }
        return ans;
    }
};
//  test case
int main() {
    Solution solution;
    std::vector<int> arr = {1, 2, 3, 5, 7, 11};
    int k = 5;
    std::vector<int> result = solution.kthSmallestPrimeFraction(arr, k);
    std::cout << "the " << k << "th smallest fraction considered is: [" << result[0] << ", " << result[1] << "]" << std::endl;
    return 0;
}
