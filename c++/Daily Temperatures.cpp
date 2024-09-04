#include <vector>
#include <stack>
#include <iostream>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        int n = temperatures.size();
        std::vector<int> answer(n, 0);
        std::stack<int> stack;

        for (int i = 0; i < n; ++i) {
            while (!stack.empty() && temperatures[i] > temperatures[stack.top()]) {
                int prev_index = stack.top();
                stack.pop();
                answer[prev_index] = i - prev_index;
            }
            stack.push(i);
        }

        return answer;
    }
};

int main() {
    Solution object;

    // Case 1
    std::vector<int> temperatures1 = {73, 74, 75, 71, 69, 72, 76, 73};
    std::vector<int> result1 = object.dailyTemperatures(temperatures1);

    std::cout << "Case 1: ";
    for (int days : result1) {
        std::cout << days << " ";
    }
    std::cout << std::endl;
    
    // Case 2
    std::vector<int> temperatures2 = {70, 70, 70, 70};
    std::vector<int> result2 = object.dailyTemperatures(temperatures2);

    std::cout << "Case 2: ";
    for (int days : result2) {
        std::cout << days << " ";
    }
    std::cout << std::endl;

    return 0;
}