#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minHeightShelves(std::vector<std::vector<int>>& books, int shelfWidth) {
        int n = books.size();
        std::vector<int> dp(n + 1, INT_MAX); 
        dp[0] = 0; 

        for (int i = 1; i <= n; ++i) {
            int width = 0;
            int height = 0;
            for (int j = i; j > 0; --j) {
                width += books[j - 1][0];
                if (width > shelfWidth) break;
                height = std::max(height, books[j - 1][1]);
                dp[i] = std::min(dp[i], dp[j - 1] + height);
            }
        }
        return dp[n];
    }
};
//  test case
int main() {
    std::vector<std::vector<int>> books = {{1, 1}, {2, 3}, {2, 3}, {1, 2}, {1, 1}};
    int shelfWidth = 4;

    Solution bookcase;
    int minHeight = bookcase.minHeightShelves(books, shelfWidth);
    std::cout << "Minimum possible height of the bookshelf: " << minHeight << std::endl;

    return 0;
}
