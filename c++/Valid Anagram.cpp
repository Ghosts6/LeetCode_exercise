#include<iostream>
#include<string>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) return false;

        int count[26] = {0};

        for (size_t i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }

        return true;  
    }
};

// Test cases
int main() {
   Solution solution;
   
   // case 1
   std::string s1 = "anagram";
   std::string t1 = "nagaram";
   std::cout << "result of test case 1 is : " << solution.isAnagram(s1, t1) << std::endl; // Expected: true
   // case 2
   std::string s2 = "rat";
   std::string t2 = "car";
   std::cout << "result of test case 2 is : " << solution.isAnagram(s2, t2) << std::endl; // Expected: false
   
   return 0;
}
