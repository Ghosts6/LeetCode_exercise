class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split()
        words.reverse()
        return ' '.join(words)


def test_case():
    sol = Solution()
    assert sol.reverseWords("the sky is blue") == "blue is sky the"
    assert sol.reverseWords("  hello world  ") == "world hello"
    assert sol.reverseWords("a good   example") == "example good a"

    print("All test cases passed!")

test_case()
