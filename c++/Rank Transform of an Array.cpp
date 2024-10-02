#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    std::vector<int> arrayRankTransform(std::vector<int>& arr) {
        std::vector<int> sortedArr = arr;
        std::sort(sortedArr.begin(), sortedArr.end());

        std::unordered_map<int, int> rankMap;
        int rank = 1;
        for (int num : sortedArr) {
            if (rankMap.find(num) == rankMap.end()) {
                rankMap[num] = rank++;
            }
        }

        std::vector<int> result;
        for (int num : arr) {
            result.push_back(rankMap[num]);
        }

        return result;
    }
};
//  Test cases
int main() {
    Solution solution;

    // Case 1
    std::vector<int> arr1 = {40, 10, 20, 30};
    std::vector<int> result1 = solution.arrayRankTransform(arr1);
    std::cout << "Test Case 1 Output: ";
    for (int rank : result1) {
        std::cout << rank << " ";
    }
    std::cout << std::endl;

    // Case 2
    std::vector<int> arr2 = {100, 100, 100};
    std::vector<int> result2 = solution.arrayRankTransform(arr2);
    std::cout << "Test Case 2 Output: ";
    for (int rank : result2) {
        std::cout << rank << " ";
    }
    std::cout << std::endl;

    return 0;
}
