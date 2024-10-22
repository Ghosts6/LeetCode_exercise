class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        def backtrack(start, seen):
            if start == len(s):
                return 0
            
            max_splits = 0

            for end in range(start + 1, len(s) + 1):
                substring = s[start:end]
                if substring not in seen:
                    seen.add(substring)
                    max_splits = max(max_splits, 1 + backtrack(end, seen))
                    seen.remove(substring)
            return max_splits

        return backtrack(0, set())

if __name__ == "__main__":
    solution = Solution()
    
    # case 1
    s1 = "ababccc"
    print(solution.maxUniqueSplit(s1))  # Output: 5

    # case 2
    s2 = "aba"
    print(solution.maxUniqueSplit(s2))  # Output: 2

    # case 3
    s3 = "aa"
    print(solution.maxUniqueSplit(s3))  # Output: 1
        