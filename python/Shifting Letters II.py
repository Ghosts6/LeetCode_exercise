from typing import List

class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        s = list(s)
        n = len(s)
        shift_accum = [0] * (n + 1) 
        
        for start, end, direction in shifts:
            if direction == 1:
                shift_accum[start] += 1
                shift_accum[end + 1] -= 1
            else:
                shift_accum[start] -= 1
                shift_accum[end + 1] += 1

        net_shift = 0
        for i in range(n):
            net_shift += shift_accum[i]
            shift_accum[i] = net_shift
        
        for i in range(n):
            s[i] = chr((ord(s[i]) - ord('a') + shift_accum[i]) % 26 + ord('a'))
        
        return ''.join(s)
# Test cases
if __name__ == "__main__":
    solution = Solution()
    # case 1
    s1 = "abc"
    shifts1 = [[0,1,0],[1,2,1],[0,2,1]]
    print("Output of test case 1:",solution.shiftingLetters(s1, shifts1)) # Expected Output : "ace"
    # case 2
    s2 = "dztz"
    shifts2 = [[0,0,0],[1,1,1]]
    print("Output of test case 2:",solution.shiftingLetters(s2, shifts2)) # Expected Output : "catz"
    