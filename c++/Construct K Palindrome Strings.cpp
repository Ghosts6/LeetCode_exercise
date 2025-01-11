#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class Solution {
public:
    bool canConstruct(std::string s, int k) {
        if (s.size() < k) return false;
        
        std::vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        
        int oddCount = 0;
        for (int count : freq) {
            if (count % 2 != 0) oddCount++;
        }
        
        return oddCount <= k;
    }
};

// Test case
int main() {
    Solution solution;
    // case 1
    std::string s1 = "annabelle";
    int k1 = 2;
    bool result1 = solution.canConstruct(s1 , k1);
    std::cout<<"Out put of case 1 is:"<<result1<<std::endl; // Expected Output : true

    // case 2
    std::string s2 = "leetcode";
    int k2 = 3;
    bool result2 = solution.canConstruct(s2 , k2);
    std::cout<<"Out put of case 2 is:"<<result2<<std::endl; // Expected Output : false

    // case 3
    std::string s3 = "true";
    int k3 = 4;
    bool result3 = solution.canConstruct(s3 , k3);
    std::cout<<"Out put of case 3 is:"<<result3<<std::endl; // Expected Output : true

    return 0;
}