#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class Solution {
public:
    bool areSentencesSimilar(std::string sentence1, std::string sentence2) {
        std::vector<std::string> words1 = split(sentence1);
        std::vector<std::string> words2 = split(sentence2);
        
        int i = 0, j = 0;
        int len1 = words1.size(), len2 = words2.size();

        while (i < len1 && i < len2 && words1[i] == words2[i]) {
            i++;
        }
        
        while (j < len1 - i && j < len2 - i && words1[len1 - 1 - j] == words2[len2 - 1 - j]) {
            j++;
        }
        
        return (i + j >= len1 || i + j >= len2);
    }

private:
    std::vector<std::string> split(const std::string& sentence) {
        std::vector<std::string> words;
        std::stringstream ss(sentence);
        std::string word;
        
        while (ss >> word) {
            words.push_back(word);
        }
        
        return words;
    }
};
//  Test cases
int main() {
    Solution solution;
    
    // case 1
    std::string sentence1 = "My name is Haley";
    std::string sentence2 = "My Haley";
    bool result1 = solution.areSentencesSimilar(sentence1, sentence2);
    std::cout << "Test Case 1: " << (result1 ? "True" : "False") << std::endl;

    // case 2
    std::string sentence1_2 = "of";
    std::string sentence2_2 = "A lot of words";
    bool result2 = solution.areSentencesSimilar(sentence1_2, sentence2_2);
    std::cout << "Test Case 2: " << (result2 ? "True" : "False") << std::endl;

    return 0;
}
