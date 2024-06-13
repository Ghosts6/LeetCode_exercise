#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minMovesToSeat(std::vector<int>& seats, std::vector<int>& students) {
        std::sort(seats.begin(), seats.end());
        std::sort(students.begin(), students.end());
        
        int min_moves = 0;

        for (int i = 0; i < seats.size(); ++i) {
            min_moves += abs(seats[i] - students[i]);
        }
        
        return min_moves;
    }
};
//  test cases
int main() {
    Solution solution;
    
    // case 1
    std::vector<int> seats1 = {3, 1, 5};
    std::vector<int> students1 = {2, 7, 4};
    int result1 = solution.minMovesToSeat(seats1, students1);
    std::cout << "result of test case 1: " << result1 << std::endl;
    
    // case 2
    std::vector<int> seats2 = {4, 1, 5, 9};
    std::vector<int> students2 = {1, 3, 2, 6};
    int result2 = solution.minMovesToSeat(seats2, students2);
    std::cout << "result of test case 2: " << result2 << std::endl;
        
    return 0;
}
