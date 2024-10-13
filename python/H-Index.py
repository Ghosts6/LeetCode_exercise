class Solution:
    def hIndex(self, citations):
        citations.sort(reverse=True)
        
        h_index = 0
        for i, citation in enumerate(citations):
            if citation >= i + 1:
                h_index = i + 1
            else:
                break
        
        return h_index

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # case 1
    citations1 = [3, 0, 6, 1, 5]
    print(solution.hIndex(citations1)) # Output 3
    
    # case 2
    citations2 = [1, 3, 1]
    print(solution.hIndex(citations2)) # Output 1
