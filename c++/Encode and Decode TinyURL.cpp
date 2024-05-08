#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    std::string encode(std::string longUrl) {
        return longUrl;
    }
    std::string decode(std::string shortUrl) {
        return shortUrl;
    }

};

// test case
int main() {
    Solution sol;
    std::string longUrl = "https://leetcode.com/problems/design-tinyurl";
    std::string shortUrl = sol.encode(longUrl);
    std::cout << "encode URL: " << shortUrl << std::endl; 
    std::cout << "decode URL: " << sol.decode(shortUrl) << std::endl; 
    return 0;
}

