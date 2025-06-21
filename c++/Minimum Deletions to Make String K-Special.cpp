#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cmath>

class Solution {
     public:
     int minimumDeletions(const std::string& word, int k) {
        std::unordered_map<char, int> freqMap;
        for (char ch : word) {
            freqMap[ch]++;
        }

        std::vector<int> freqs;
        for (const auto& pair : freqMap) {
            freqs.push_back(pair.second);
        }

        std::sort(freqs.begin(), freqs.end());

        int n = freqs.size();
        int res = word.size(); // Worst case: delete everything

        for (int i = 0; i < n; ++i) {
            int base = freqs[i];
            int targetMax = base + k;
            int deletions = 0;

            // Delete all frequencies below base
            for (int j = 0; j < i; ++j) {
                deletions += freqs[j]; // full delete
            }

            // Reduce all frequencies above base+k down to base+k
            for (int j = i + 1; j < n; ++j) {
                if (freqs[j] > targetMax) {
                    deletions += freqs[j] - targetMax;
                }
            }

            res = std::min(res, deletions);
        }

        return res;
    }    
};

// Test cases
int main() {
    Solution solution;

    // case 1
    std::string word1 = "aabcaba";
    int k1 = 0;
    std::cout << "Result of test case 1 is : " << solution.minimumDeletions(word1, k1) << std::endl; // Expected Output: 3

    // case 2
    std::string word2 = "dabdcbdcdcd";
    int k2 = 2;
    std::cout << "Result of test case 2 is : " << solution.minimumDeletions(word2, k2) << std::endl; // Expected Output: 2

    // case 3
    std::string word3 = "aaabaaa";
    int k3 = 2;
    std::cout << "Result of test case 3 is : " << solution.minimumDeletions(word3, k3) << std::endl; // Expected Output: 1

    return 0;
}
