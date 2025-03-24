#include<iostream>
#include<vector>
#include <algorithm>

class Solution {
public:
    int countDays(int days, std::vector<std::vector<int>>& meetings) {
        std::sort(meetings.begin(), meetings.end());

        long long busyDays = 0;
        int lastEnd = 0;

        for (const auto& meeting : meetings) {
            if (meeting[1] > lastEnd) {
                busyDays += meeting[1] - std::max(lastEnd + 1, meeting[0]) + 1;
                lastEnd = meeting[1];
            }
        }

        return days - busyDays;
    }
};

// Test cases
int main() {
    Solution solution;
    // case 1
    int days1 = 10;
    std::vector<std::vector<int>> meetings1 = {{5,7},{1,3},{9,10}};
    std::cout << "result of test case 1 : " << solution.countDays(days1, meetings1) << std::endl; // Expected Output: 2 
    // case 2
    int days2 = 5;
    std::vector<std::vector<int>> meetings2 = {{2,4},{1,3}};
    std::cout << "result of test case 2 : " << solution.countDays(days2, meetings2) << std::endl; // Expected Output: 1
    // case 3
    int days3 = 6;
    std::vector<std::vector<int>> meetings3 = {{1,6}};
    std::cout << "result of test case 3 : " << solution.countDays(days3, meetings3) << std::endl; // Expected Output: 0

    return 0;
}
    