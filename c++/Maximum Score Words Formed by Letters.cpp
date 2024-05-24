#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int maxScoreWords(std::vector<std::string>& words, std::vector<char>& letters, std::vector<int>& score) {
        std::unordered_map<char, int> letterCount;
        for (char letter : letters) {
            letterCount[letter]++;
        }
        return dfs(words, score, letterCount, 0);
    }
private:
    int dfs(const std::vector<std::string>& words, const std::vector<int>& score, std::unordered_map<char, int>& letterCount, int index) {
        if (index == words.size()) return 0; 
        std::unordered_map<char, int> tempCount = letterCount;
        int wordScore = 0;
        bool canForm = true;
        
        for (char c : words[index]) {
            if (--tempCount[c] < 0) {
                canForm = false;
            }
            wordScore += score[c - 'a'];
        }

        int skipWord = dfs(words, score, letterCount, index + 1);
        if (!canForm) {
            return skipWord;
        }
        int includeWord = wordScore + dfs(words, score, tempCount, index + 1);
        return std::max(skipWord, includeWord);
    }
};
//  test case
int main() {
    Solution solution;
    
    std::vector<std::string> words1 = {"dog", "cat", "dad", "good"};
    std::vector<char> letters1 = {'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'};
    std::vector<int> score1 = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    std::cout << "Max score for words1: " << solution.maxScoreWords(words1, letters1, score1) << std::endl;
    
    std::vector<std::string> words2 = {"xxxz", "ax", "bx", "cx"};
    std::vector<char> letters2 = {'z', 'a', 'b', 'c', 'x', 'x', 'x'};
    std::vector<int> score2 = {4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10};
    std::cout << "Max score for words2: " << solution.maxScoreWords(words2, letters2, score2) << std::endl;
    

    return 0;
}
