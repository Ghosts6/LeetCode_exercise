# 📜 Daily Temperatures


## 💡 Intuition
The goal is to find out how many days you would have to wait until a warmer temperature for each day. To achieve this, we can use a stack to keep track of the indices of the days.

## 🛠️ Approach
1.  Stack Usage: Use a stack to store indices of days for which we haven't found a warmer day yet. The stack is used because it allows us to efficiently track the most recent days where we still need to find a warmer temperature.

2.  Iterate Over the Temperatures: For each day's temperature:
While the stack is not empty, and the current day's temperature is greater than the temperature at the index stored at the top of the stack, pop the stack. This means we've found a warmer day for the day at the index on top of the stack.
Calculate the difference in days between the current index and the index popped from the stack, and store it in the result array.
Push the current index onto the stack.

3.  Return the Result: The answer array will contain the number of days you have to wait until a warmer temperature.

## ⏰ Complexity
- Time complexity:
The time complexity of this approach is O(n), where n is the number of temperatures.

- Space complexity:
The space complexity is O(n), where n is the number of temperatures.

## 💻 Code
```python3 []
class Solution:
    def dailyTemperatures(self, temperatures):
        n = len(temperatures)
        answer = [0] * n
        stack = []

        for i in range(n):
            while stack and temperatures[i] > temperatures[stack[-1]]:
                prev_index = stack.pop()
                answer[prev_index] = i - prev_index
            stack.append(i)
        
        return answer
```
```C++ []
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
```