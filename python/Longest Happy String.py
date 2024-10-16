import heapq

class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        heap = []
        for count, char in [(-a, 'a'), (-b, 'b'), (-c, 'c')]:
            if count != 0:
                heapq.heappush(heap, (count, char))
        
        result = []
        
        while heap:
            count1, char1 = heapq.heappop(heap)

            if len(result) >= 2 and result[-1] == result[-2] == char1:
                if not heap:
                    break  

                count2, char2 = heapq.heappop(heap)
                result.append(char2)
                count2 += 1  
                
                if count2 != 0:
                    heapq.heappush(heap, (count2, char2))

                heapq.heappush(heap, (count1, char1))
            else:
                result.append(char1)
                count1 += 1  
                if count1 != 0:
                    heapq.heappush(heap, (count1, char1))
        
        return ''.join(result)

# Test cases
if __name__ == "__main__":
    # case 1
    solution = Solution()
    a, b, c = 1, 1, 7
    print(solution.longestDiverseString(a, b, c))  # Output: "ccaccbcc"
    
    # case 2
    a, b, c = 7, 1, 0
    print(solution.longestDiverseString(a, b, c))  # Output: "aabaa"
