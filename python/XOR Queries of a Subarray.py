class Solution:
    def xorQueries(self, arr, queries):
        n = len(arr)
        prefix = [0] * (n + 1) 
        
        for i in range(1, n + 1):
            prefix[i] = prefix[i - 1] ^ arr[i - 1]

        result = []
        for left, right in queries:
            result.append(prefix[right + 1] ^ prefix[left])
        
        return result

# Test cases
s = Solution()

# case 1
arr1 = [1, 3, 4, 8]
queries1 = [[0, 1], [1, 2], [0, 3], [3, 3]]
print(s.xorQueries(arr1, queries1))  # Expected output: [2, 7, 14, 8]

# case 2
arr2 = [4, 8, 2, 10]
queries2 = [[2, 3], [1, 3], [0, 0], [0, 3]]
print(s.xorQueries(arr2, queries2))  # Expected output: [8, 0, 4, 4]