#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    std::vector<int> partitionLabels(std::string s) {
        std::vector<int> result;
        std::unordered_map<char, int> last_occurrence;

        for (int i = 0; i < s.size(); ++i) {
            last_occurrence[s[i]] = i;
        }

        int start = 0;
        int end = 0;

        for (int i = 0; i < s.size(); ++i) {
            end = std::max(end, last_occurrence[s[i]]);
            if (i == end) {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return result;
    }
};
//  test case
int main() {
    Solution solution;
    std::string s = "ababcbacadefegdehijhklij";
    std::vector<int> result = solution.partitionLabels(s);
    
    std::cout << "partition sizes: ";
    for (int size : result) {
        std::cout << size << " ";
    }
    std::cout << std::endl;

    return 0;
}
