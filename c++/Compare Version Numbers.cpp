#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
        std::vector<int> v1 = split(version1);
        std::vector<int> v2 = split(version2);
        int n = std::max(v1.size(), v2.size());
        for (int i = 0; i < n; ++i) {
            int num1 = (i < v1.size()) ? v1[i] : 0;
            int num2 = (i < v2.size()) ? v2[i] : 0;
            
            if (num1 < num2) return -1;
            else if (num1 > num2) return 1;
        }
        return 0;
    }
private:
    std::vector<int> split(const std::string& version) {
        std::vector<int> result;
        std::stringstream ss(version);
        std::string token;
        while (std::getline(ss, token, '.')) {
            result.push_back(std::stoi(token));
        }
        return result;
    }
};
//  test case
int main() {
    Solution sol;
    std::string version1 = "1.2.3";
    std::string version2 = "1.2.4";
    int result = sol.compareVersion(version1, version2);
    std::cout << "result: " << result << std::endl;
    return 0;
}