import heapq

class Solution:
    def findKthLargest(self, nums, k):
        min_heap = []
        
        for num in nums:
            heapq.heappush(min_heap, num)
            if len(min_heap) > k:
                heapq.heappop(min_heap)
 
        return min_heap[0]


# Test case 
nums1 = [3, 2, 1, 5, 6, 4]
k1 = 2
sol = Solution()
result1 = sol.findKthLargest(nums1, k1)
print(f"The {k1}th largest element in {nums1} is {result1}.")
