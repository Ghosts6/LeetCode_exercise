import random

class Solution:
    def __init__(self, w: list[int]):
        self.prefix_sums = []
        cumulative_sum = 0
        for weight in w:
            cumulative_sum += weight
            self.prefix_sums.append(cumulative_sum)
        self.total_sum = cumulative_sum

    def pickIndex(self) -> int:
        target = int(random.random() * self.total_sum) + 1

        left, right = 0, len(self.prefix_sums) - 1
        while left < right:
            mid = (left + right) // 2
            if self.prefix_sums[mid] < target:
                left = mid + 1
            else:
                right = mid
        return left

# Test cases 
if __name__ == "__main__":
    # Case 1
    solution = Solution([1])
    print(solution.pickIndex())  # Expected 0

    # Case 2
    solution = Solution([1, 3])
    results = [solution.pickIndex() for _ in range(10)]
    print(results)  # Expected: [1, 1, 1, 1, 0, 1, 1, 1, 0, 1]

