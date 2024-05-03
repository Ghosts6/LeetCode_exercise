#include <vector>

class Solution {
public:
    std::vector<double> convertTemperature(double celsius) {
        std::vector<double> ans(2);
        ans[0] = celsius + 273.15;
        ans[1] = celsius * 1.80 + 32.00;
        return ans;
    }
};
