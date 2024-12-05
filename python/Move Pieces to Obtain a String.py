class Solution:
    def canChange(self, start: str, target: str) -> bool:
        s_filtered = [(ch, i) for i, ch in enumerate(start) if ch in 'LR']
        t_filtered = [(ch, i) for i, ch in enumerate(target) if ch in 'LR']
        
        if len(s_filtered) != len(t_filtered) or any(s[0] != t[0] for s, t in zip(s_filtered, t_filtered)):
            return False

        for (s_char, s_idx), (t_char, t_idx) in zip(s_filtered, t_filtered):
            if (s_char == 'L' and s_idx < t_idx) or (s_char == 'R' and s_idx > t_idx):
                return False
        
        return True
# Test cases
if __name__ == "__main__":
    sol = Solution()
    
    # case 1
    start1, target1, expected1 = "_L__R__R_", "L______RR", True
    result1 = sol.canChange(start1, target1)
    print(f"Start: '{start1}', Target: '{target1}', Result: {result1}, Expected: {expected1}")
    assert result1 == expected1, f"Test failed for Start: '{start1}', Target: '{target1}'"
    
    # case 2
    start2, target2, expected2 = "R_L_", "__LR", False
    result2 = sol.canChange(start2, target2)
    print(f"Start: '{start2}', Target: '{target2}', Result: {result2}, Expected: {expected2}")
    assert result2 == expected2, f"Test failed for Start: '{start2}', Target: '{target2}'"
    
    # case 3
    start3, target3, expected3 = "_R", "R_", False
    result3 = sol.canChange(start3, target3)
    print(f"Start: '{start3}', Target: '{target3}', Result: {result3}, Expected: {expected3}")
    assert result3 == expected3, f"Test failed for Start: '{start3}', Target: '{target3}'"
    