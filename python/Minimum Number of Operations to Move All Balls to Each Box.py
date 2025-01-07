from typing import List

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
# Test cases
if __name__ == "__main__":
    solution = Solution()
if __name__ == "__main__":
    solution = Solution()
    # Case 1
    boxes1 = "110"
    result1 = solution.minOperations(boxes1)
    print("Output of Test Case 1:")
    print(f"Input: {boxes1}")
    print(f"Output: {' '.join(map(str, result1))}")  # Expected Output: 1 1 3
    # Case 2
    boxes2 = "001011"
    result2 = solution.minOperations(boxes2)
    print("\nOutput of Test Case 2:")
    print(f"Input: {boxes2}")
    print(f"Output: {' '.join(map(str, result2))}")  # Expected Output: 11 8 5 4 3
