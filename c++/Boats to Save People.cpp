#include <vector>
#include <algorithm>
#include <cassert>

class Solution {
public:
    int numRescueBoats(std::vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());
        int left = 0, right = people.size() - 1;
        int boats = 0;
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++;
                right--;
            } else {
                right--;
            }
            boats++;
        }
        return boats;
    }
};

// test case
int main() {
    Solution sol;
    std::vector<int> people1 = {1, 2};
    int limit1 = 3;
    assert(sol.numRescueBoats(people1, limit1) == 1);
    return 0;
}
