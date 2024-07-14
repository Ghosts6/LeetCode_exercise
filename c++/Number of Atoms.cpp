#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <stack>
#include <cctype>

class Solution {
public:
    std::string countOfAtoms(std::string formula) {
        std::unordered_map<std::string, int> atomCount = parseFormula(formula, 0).first;

        std::map<std::string, int> sortedAtoms(atomCount.begin(), atomCount.end());

        std::string result;
        for (const auto& atom : sortedAtoms) {
            result += atom.first;
            if (atom.second > 1) {
                result += std::to_string(atom.second);
            }
        }
        return result;
    }

private:
    std::pair<std::unordered_map<std::string, int>, int> parseFormula(const std::string& formula, int start) {
        std::unordered_map<std::string, int> atomCount;
        int i = start;
        int n = formula.size();

        while (i < n) {
            if (formula[i] == '(') {
                int j = i + 1, depth = 1;
                while (j < n && depth > 0) {
                    if (formula[j] == '(') depth++;
                    if (formula[j] == ')') depth--;
                    j++;
                }
                int groupMultiplier = 0;
                int k = j;
                while (k < n && isdigit(formula[k])) {
                    groupMultiplier = groupMultiplier * 10 + (formula[k] - '0');
                    k++;
                }
                groupMultiplier = groupMultiplier == 0 ? 1 : groupMultiplier;
                auto subFormula = parseFormula(formula.substr(i + 1, j - i - 2), 0).first;
                for (const auto& elem : subFormula) {
                    atomCount[elem.first] += elem.second * groupMultiplier;
                }
                i = k;
            } else {
                int j = i + 1;
                while (j < n && islower(formula[j])) j++;
                std::string element = formula.substr(i, j - i);
                int count = 0;
                while (j < n && isdigit(formula[j])) {
                    count = count * 10 + (formula[j] - '0');
                    j++;
                }
                count = count == 0 ? 1 : count;
                atomCount[element] += count;
                i = j;
            }
        }

        return {atomCount, i};
    }
};
//  test cases
int main() {
    Solution solution;

    std::string test1 = "H2O";
    std::string test2 = "Mg(OH)2";
    std::string test3 = "K4(ON(SO3)2)2";

    std::cout << "Test case 1: " << test1 << " -> " << solution.countOfAtoms(test1) << std::endl;
    std::cout << "Test case 2: " << test2 << " -> " << solution.countOfAtoms(test2) << std::endl;
    std::cout << "Test case 3: " << test3 << " -> " << solution.countOfAtoms(test3) << std::endl;

    return 0;
}
