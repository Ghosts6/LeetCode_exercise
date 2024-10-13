import heapq

class Solution:
    def smallestRange(self, nums):
        min_heap = []
        current_max = float('-inf')

        for i in range(len(nums)):
            heapq.heappush(min_heap, (nums[i][0], i, 0))
            current_max = max(current_max, nums[i][0])

        smallest_range = [float('-inf'), float('inf')]
        
        while min_heap:
            current_min, list_idx, ele_idx = heapq.heappop(min_heap)

            if current_max - current_min < smallest_range[1] - smallest_range[0]:
                smallest_range = [current_min, current_max]

            if ele_idx + 1 == len(nums[list_idx]):
                break

            next_element = nums[list_idx][ele_idx + 1]
            heapq.heappush(min_heap, (next_element, list_idx, ele_idx + 1))

            current_max = max(current_max, next_element)
        
        return smallest_range

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # case 1
    nums1 = [[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
    print(solution.smallestRange(nums1)) # Output
    
    # case 2
    nums2 = [[1,2,3], [1,2,3], [1,2,3]]
    print(solution.smallestRange(nums2)) # Output
