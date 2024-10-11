#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

class Solution {
public:
    int smallestChair(std::vector<std::vector<int>>& times, int targetFriend) {
        int n = times.size();

        std::vector<int> order(n);
        for (int i = 0; i < n; ++i) order[i] = i;

        std::sort(order.begin(), order.end(), [&times](int a, int b) {
            return times[a][0] < times[b][0];
        });

        std::priority_queue<int, std::vector<int>, std::greater<int>> emptySeats; 
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> takenSeats; 

        for (int i = 0; i < n; ++i) emptySeats.push(i);

        for (int i : order) {
            int arrival = times[i][0], leave = times[i][1];

            while (!takenSeats.empty() && takenSeats.top().first <= arrival) {
                emptySeats.push(takenSeats.top().second);
                takenSeats.pop();
            }

            int seat = emptySeats.top();
            emptySeats.pop();

            if (i == targetFriend) return seat;

            takenSeats.push({leave, seat});
        }

        return -1; 
    }
};

int main() {
    Solution solution;

    // case 1
    std::vector<std::vector<int>> times1 = {{1, 4}, {2, 3}, {4, 6}};
    int targetFriend1 = 1;
    int result1 = solution.smallestChair(times1, targetFriend1);
    std::cout << "Test Case 1 Result: " << result1 << " (Expected: 1)" << std::endl;

    // case 2
    std::vector<std::vector<int>> times2 = {{3, 10}, {1, 5}, {2, 6}};
    int targetFriend2 = 0;
    int result2 = solution.smallestChair(times2, targetFriend2);
    std::cout << "Test Case 2 Result: " << result2 << " (Expected: 2)" << std::endl;

    return 0;
}
