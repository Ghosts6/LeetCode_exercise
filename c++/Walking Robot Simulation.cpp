#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int robotSim(std::vector<int>& commands, std::vector<std::vector<int>>& obstacles) {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        std::unordered_set<std::string> obstacleSet;
        for (const auto& obs : obstacles) {
            obstacleSet.insert(std::to_string(obs[0]) + "," + std::to_string(obs[1]));
        }

        int x = 0, y = 0; 
        int direction = 0; 
        int maxDistSq = 0;

        for (int command : commands) {

            if (command == -2) {
                direction = (direction + 3) % 4;
            } else if (command == -1) {
                direction = (direction + 1) % 4;
            } else {
                for (int i = 0; i < command; ++i) {
                    int newX = x + dx[direction];
                    int newY = y + dy[direction];

                    if (obstacleSet.find(std::to_string(newX) + "," + std::to_string(newY)) != obstacleSet.end()) {
                        break; 
                    }

                    x = newX;
                    y = newY;

                    maxDistSq = std::max(maxDistSq, x * x + y * y);
                }
            }
        }

        return maxDistSq;
    }
};

// Test cases 
int main() {
    Solution robot;

    // Case 1
    std::vector<int> commands1 = {4, -1, 3};
    std::vector<std::vector<int>> obstacles1 = {};
    int result1 = robot.robotSim(commands1, obstacles1);
    std::cout << "Test Case 1 Result: " << result1 << " (Expected: 25)" << std::endl;

    // Case 2
    std::vector<int> commands2 = {4, -1, 4, -2, 4};
    std::vector<std::vector<int>> obstacles2 = {{2, 4}};
    int result2 = robot.robotSim(commands2, obstacles2);
    std::cout << "Test Case 2 Result: " << result2 << " (Expected: 65)" << std::endl;

    return 0;
}
