#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> findWordsContaining(std::vector<std::string>& words, char x) {
        std::vector<int> result;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i].find(x) != std::string::npos) {
                result.push_back(i);
            }
        }
        return result;
    }
};
//  test case
int main() {
    Solution sol;
    std::vector<std::string> words = {"apple", "banana", "orange", "grape"};
    char x = 'n';
    std::vector<int> indices = sol.findWordsContaining(words, x);
    std::cout << "Indices of words containing character '" << x << "': ";
    for (int index : indices) {
        std::cout << index << " ";
    }
    std::cout << std::endl;
    return 0;
}
