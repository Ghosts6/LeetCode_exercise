import heapq

class Solution:
    def totalCost(self, costs, k, candidates):
        n = len(costs)
        left = 0
        right = n - 1
        left_heap = []
        right_heap = []

        for i in range(candidates):
            if left <= right:
                heapq.heappush(left_heap, (costs[left], left))
                left += 1
            if left <= right:
                heapq.heappush(right_heap, (costs[right], right))
                right -= 1
        
        total_cost = 0

        for _ in range(k):
            if not right_heap or (left_heap and left_heap[0][0] <= right_heap[0][0]):
                cost, idx = heapq.heappop(left_heap)
                total_cost += cost
                if left <= right:
                    heapq.heappush(left_heap, (costs[left], left))
                    left += 1
            else:
                cost, idx = heapq.heappop(right_heap)
                total_cost += cost
                if left <= right:
                    heapq.heappush(right_heap, (costs[right], right))
                    right -= 1
        
        return total_cost

# Test cases
solution = Solution()
costs1 = [3, 2, 7, 7, 1, 2]
k1 = 3
candidates1 = 2
print(solution.totalCost(costs1, k1, candidates1))
