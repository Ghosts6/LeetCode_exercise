# 📜 Minimum Number of Operations to Move All Balls to Each Box

## 💡 Intuition
The problem requires calculating the minimum number of operations to move all balls to each box. The key observation is that the number of operations to move balls to a box depends on the distance of the balls from that box. By iterating through the boxes from left to right and then from right to left, we can accumulate the number of moves required efficiently.

## 🛠️ Approach
1. Initialize an array `result` to store the number of operations for each box.
2. Perform a left-to-right pass:
   - Track the number of moves and the count of balls encountered so far.
   - For each box, add the current number of moves to the result and update the count and moves if the current box contains a ball.
3. Perform a right-to-left pass:
   - Reset the moves and count.
   - For each box, add the current number of moves to the result and update the count and moves if the current box contains a ball.
4. Return the result array.

## ⏰ Complexity
- Time complexity: O(n), where n is the number of boxes. We iterate through the boxes twice (left-to-right and right-to-left).
- Space complexity: O(n), where n is the number of boxes. We use an additional array to store the result.

# 💻 Code
```c []
int* minOperations(char* boxes, int* returnSize) {
    int n = strlen(boxes);  
    *returnSize = n; 

    int* result = (int*)malloc(n * sizeof(int));
    memset(result, 0, n * sizeof(int));

    int moves = 0, count = 0;
    for (int i = 0; i < n; ++i) {
        result[i] += moves;
        count += boxes[i] == '1' ? 1 : 0;
        moves += count;
    }

    moves = 0;
    count = 0;
    for (int i = n - 1; i >= 0; --i) {
        result[i] += moves;
        count += boxes[i] == '1' ? 1 : 0;
        moves += count;
    }

    return result;
}
```
```C++ []
class Solution {
    public:
    std::vector<int> minOperations(const std::string& boxes) {
        int n = boxes.size();
        std::vector<int> result(n, 0);

        int moves = 0, count = 0;
        for (int i = 0; i < n; ++i) {
            result[i] += moves;
            count += boxes[i] == '1' ? 1 : 0;
            moves += count;
        }

        moves = 0, count = 0;
        for (int i = n - 1; i >= 0; --i) {
            result[i] += moves;
            count += boxes[i] == '1' ? 1 : 0;
            moves += count;
        }

        return result;
    }
};
```
```Python3 []
class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        result = [0] * n

        moves, count = 0, 0
        for i in range(n):
            result[i] += moves
            count += 1 if boxes[i] == '1' else 0
            moves += count

        moves, count = 0, 0
        for i in range(n - 1, -1, -1):
            result[i] += moves
            count += 1 if boxes[i] == '1' else 0
            moves += count

        return result
```