#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfitAssignment(std::vector<int>& difficulty, std::vector<int>& profit, std::vector<int>& worker) {
        int n = difficulty.size();
        std::vector<std::pair<int, int>> jobs(n);
        
        for (int i = 0; i < n; ++i) {
            jobs[i] = {difficulty[i], profit[i]};
        }

        std::sort(jobs.begin(), jobs.end());
        std::sort(worker.begin(), worker.end());
        
        int maxProfit = 0, best = 0, i = 0;
        for (int ability : worker) {
            while (i < n && ability >= jobs[i].first) {
                best = std::max(best, jobs[i].second);
                ++i;
            }
            maxProfit += best;
        }
        
        return maxProfit;
    }
};

// test case
int main() {
    Solution solution;
    
    std::vector<int> difficulty = {2, 4, 6, 8, 10};
    std::vector<int> profit = {10, 20, 30, 40, 50};
    std::vector<int> worker = {4, 5, 6, 7};
    int result = solution.maxProfitAssignment(difficulty, profit, worker);
    std::cout << "result of test case : " << result << std::endl;

    return 0;

}