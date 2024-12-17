from collections import Counter
import heapq

class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        freq = Counter(s)
        max_heap = [(-ord(ch), ch, count) for ch, count in freq.items()]
        heapq.heapify(max_heap)
        
        result = []
        
        while max_heap:
            _, char, count = heapq.heappop(max_heap)
            can_use = min(count, repeatLimit)
            
            result.append(char * can_use)
            
            if count > can_use: 
                if not max_heap:  
                    break
                _, next_char, next_count = heapq.heappop(max_heap)
                result.append(next_char) 
                
                if next_count > 1:
                    heapq.heappush(max_heap, (-ord(next_char), next_char, next_count - 1))
                heapq.heappush(max_heap, (-ord(char), char, count - can_use))
        
        return ''.join(result)

# Test cases
if __name__ == "__main__":
    solution = Solution()
    # case 1
    s1 = "cczazcc"
    repeatLimit1 = 3
    print("Test Case 1:", solution.repeatLimitedString(s1, repeatLimit1))  # Output: "zzcccac"

    # case 2
    s2 = "aababab"
    repeatLimit2 = 2
    print("Test Case 2:", solution.repeatLimitedString(s2, repeatLimit2))  # Output: "bbabaa"
