from collections import Counter
import heapq

class Solution:
    def isNStraightHand(self, hand, groupSize):
        if len(hand) % groupSize != 0:
            return False
        
        count = Counter(hand)
        min_heap = list(count.keys())
        heapq.heapify(min_heap)
        
        while min_heap:
            first = min_heap[0]
            for i in range(first, first + groupSize):
                if count[i] == 0:
                    return False
                count[i] -= 1
                if count[i] == 0:
                    if i != min_heap[0]:
                        return False
                    heapq.heappop(min_heap)
        
        return True

# test cases
sol = Solution()
print(sol.isNStraightHand([1,2,3,6,2,3,4,7,8], 3)) 
print(sol.isNStraightHand([1,2,3,4,5], 4)) 
