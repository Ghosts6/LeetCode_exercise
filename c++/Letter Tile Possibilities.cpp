#include <iostream>
#include <unordered_set>
#include <string>

class Solution {
    public:
        int numTilePossibilities(std::string tiles) {
            std::unordered_set<std::string> uniqueSequences;
            backtrack(tiles, "", uniqueSequences);
            return uniqueSequences.size();
        }
        
    private:
        void backtrack(std::string tiles, std::string current, std::unordered_set<std::string>& uniqueSequences) {
            if (!current.empty()) {
                uniqueSequences.insert(current);
            }
            for (int i = 0; i < tiles.size(); ++i) {
                if (i > 0 && tiles[i] == tiles[i - 1]) continue;
                std::swap(tiles[i], tiles[tiles.size() - 1]);
                backtrack(tiles.substr(0, tiles.size() - 1), current + tiles[tiles.size() - 1], uniqueSequences);
                std::swap(tiles[i], tiles[tiles.size() - 1]);
            }
        }
};

// Test case
int main() {
    Solution solution;

    // case 1
    std::cout << solution.numTilePossibilities("AAB") << std::endl;   // Expected output: 8
    // case 2
    std::cout << solution.numTilePossibilities("AAABBC") << std::endl; // Expected output: 188
    // case 3
    std::cout << solution.numTilePossibilities("V") << std::endl;     // Expected output: 1

    return 0;
}