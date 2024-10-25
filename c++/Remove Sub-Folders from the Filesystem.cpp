#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> removeSubfolders(std::vector<std::string>& folder) {
        std::sort(folder.begin(), folder.end());
        std::vector<std::string> result;
        
        for (const auto& f : folder) {
            if (result.empty() || f.find(result.back() + "/") != 0) {
                result.push_back(f); 
            }
        }
        
        return result;
    }
};

// Test cases
int main() {
    Solution solution;
    std::vector<std::string> folder1 = {"/a","/a/b","/c/d","/c/d/e","/c/f"};
    std::vector<std::string> result1 = solution.removeSubfolders(folder1);
    std::cout << "Result 1: ";
    for (const auto& folder : result1) {
        std::cout << folder << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> folder2 = {"/a","/a/b/c","/a/b/d"};
    std::vector<std::string> result2 = solution.removeSubfolders(folder2);
    std::cout << "Result 2: ";
    for (const auto& folder : result2) {
        std::cout << folder << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> folder3 = {"/a/b/c","/a/b/ca","/a/b/d"};
    std::vector<std::string> result3 = solution.removeSubfolders(folder3);
    std::cout << "Result 3: ";
    for (const auto& folder : result3) {
        std::cout << folder << " ";
    }
    std::cout << std::endl;

    return 0;
}
