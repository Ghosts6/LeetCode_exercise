class Solution:
    def possibleStringCount(self, word: str) -> int:
        n = len(word)
        groups = []
        i = 0

        while i < n:
            j = i
            while j < n and word[j] == word[i]:
                j += 1
            groups.append((word[i], j - i))
            i = j

        res = 1

        for _, count in groups:
            if count > 1:
                res += count - 1

        return res

# Test cases
if __name__ == "__main__":
    sol = Solution()
    # case 1
    print(f"result of test case 1 : {sol.possibleStringCount("abbcccc")}") # Expected Output: 5
    
    # case 2
    print(f"result of test case 2 : {sol.possibleStringCount("abcd")}") # Expected Output: 1
    
    # case 3
    print(f"result of test case 3 : {sol.possibleStringCount("aaaa")}") # Expected Output: 4

