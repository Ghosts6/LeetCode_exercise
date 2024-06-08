#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    std::string reverseVowels(std::string s) {
        std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

            while (left < right && vowels.find(s[left]) == vowels.end()) {
                ++left;
            }

            while (left < right && vowels.find(s[right]) == vowels.end()) {
                --right;
            }

            if (left < right) {
                std::swap(s[left], s[right]);
                ++left;
                --right;
            }
        }

        return s;
    }
};
//  test case
int main(){
    Solution sol;
    
    std::string test = "hello";
    std::cout << "test: " << (sol.reverseVowels(test) == "holle" ? "Passed" : "Failed") << std::endl;

    return 0;
}