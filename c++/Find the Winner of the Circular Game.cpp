#include <iostream>
#include <vector>

class Solution {
public:
    int findTheWinner(int n, int k) {
        std::vector<int> friends;
        for (int i = 1; i <= n; ++i) {
            friends.push_back(i);
        }

        int currentIndex = 0;
        while (friends.size() > 1) {
            currentIndex = (currentIndex + k - 1) % friends.size();
            friends.erase(friends.begin() + currentIndex);
        }

        return friends[0];
    }
};

// test case
int main() {
    Solution game;
    int n = 5;
    int k = 2;
    int winner = game.findTheWinner(n, k);
    std::cout << "The winner is friend: " << winner << std::endl;

    return 0;
}