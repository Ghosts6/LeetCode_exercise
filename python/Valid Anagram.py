class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        count = [0] * 26

        for ch1, ch2 in zip(s, t):
            count[ord(ch1) - ord('a')] += 1
            count[ord(ch2) - ord('a')] -= 1

        return all(c == 0 for c in count)
# Test cases
if __name__ == "__main__":
    solution = Solution();

    # case 1
    s1 = "anagram"
    t1 = "nagaram"
    print(f"result of test case 1 : {solution.isAnagram(s1, t1)}") # Expected: true
    
    # case 2
    s2 = "rat"
    t2 = "car"
    print(f"result of test case 2 : {solution.isAnagram(s2, t2)}") # Expected: false
