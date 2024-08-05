import heapq

class Solution:
    def maxScore(self, nums1, nums2, k):
        
        pairs = list(zip(nums1, nums2))
        pairs.sort(key=lambda x: -x[1])

        max_heap = []
        sum_nums1 = 0
        max_score = 0
        
        for num1, num2 in pairs:
            heapq.heappush(max_heap, num1)
            sum_nums1 += num1
            
            if len(max_heap) > k:
                sum_nums1 -= heapq.heappop(max_heap)

            if len(max_heap) == k:
                max_score = max(max_score, sum_nums1 * num2)
                
        return max_score

# Test cases
if __name__ == "__main__":
    sol = Solution()
 
    nums1_1 = [1, 3, 3, 2]
    nums2_1 = [2, 1, 3, 4]
    k1 = 3
    print(sol.maxScore(nums1_1, nums2_1, k1))  

    nums1_2 = [4, 2, 3, 1]
    nums2_2 = [2, 5, 1, 5]
    k2 = 3
    print(sol.maxScore(nums1_2, nums2_2, k2)) 

