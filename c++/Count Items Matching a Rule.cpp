#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    int countMatches(std::vector<std::vector<std::string>>& items, std::string ruleKey, std::string ruleValue) {
        int count = 0;
        int keyIndex = 0;
        if (ruleKey == "color") keyIndex = 1;
        else if (ruleKey == "name") keyIndex = 2;
        for (const auto& item : items) {
            if (item[keyIndex] == ruleValue)
                count++;
        }
        return count;
    }
};
//  test case
int main() {
    Solution solution;
    std::vector<std::vector<std::string>> items = {{"phone","blue","pixel"},{"computer","silver","lenovo"},{"phone","gold","iphone"}};
    std::string ruleKey = "color";
    std::string ruleValue = "silver";
    int matches = solution.countMatches(items, ruleKey, ruleValue);
    std::cout << "number of items that match the rule: " << matches << std::endl;
    return 0;
}
