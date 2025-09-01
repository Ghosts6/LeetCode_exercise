import heapq
from typing import List

class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        """
        Distribute extra students across classes to maximize the average pass ratio.
        """
        
        def gain(p: int, t: int) -> float:
            return (p + 1) / (t + 1) - p / t

        # Max-heap simulated by storing negative gains
        heap = [(-gain(p, t), p, t) for p, t in classes]
        heapq.heapify(heap)

        for _ in range(extraStudents):
            g, p, t = heapq.heappop(heap)
            p, t = p + 1, t + 1
            heapq.heappush(heap, (-gain(p, t), p, t))

        total_average = sum(p / t for _, p, t in heap)
        return total_average / len(classes)

# Test cases
if __name__ == "__main__":
    sol = Solution()

    # case 1
    classes1 = [[1, 2], [3, 5], [2, 2]]
    extraStudents1 = 2
    print(f"Result of test case 1 : {sol.maxAverageRatio(classes1, extraStudents1)}")  # Expected ~0.78333

    # case 2
    classes2 = [[2, 4], [3, 9], [4, 5], [2, 10]]
    extraStudents2 = 4
    print(f"Result of test case 2 : {sol.maxAverageRatio(classes2, extraStudents2)}")  # Expected ~0.53485

