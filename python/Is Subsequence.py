class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if not s:
            return True
        
        s_index, t_index = 0, 0
        while t_index < len(t):
            if t[t_index] == s[s_index]:
                s_index += 1
                if s_index == len(s):
                    return True
            t_index += 1
        return False

# test cases
if __name__ == "__main__":
    solution = Solution()
    
    # case 1
    s1 = "abc"
    t1 = "ahbgdc"
    result1 = solution.isSubsequence(s1, t1)
    print(f"Is '{s1}' a subsequence of '{t1}': {result1}")
    
    # case 2
    s2 = "axc"
    t2 = "ahbgdc"
    result2 = solution.isSubsequence(s2, t2)
    print(f"Is '{s2}' a subsequence of '{t2}': {result2}")
    
