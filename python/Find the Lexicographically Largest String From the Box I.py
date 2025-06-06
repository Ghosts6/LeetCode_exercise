class Solution:
    def answerString(self, word: str, numFriends: int) -> str:
        """
        Returns the lexicographically largest string that can be formed by splitting the input word
        """
        if numFriends == 1:
            return word 
        max_len = len(word) - (numFriends - 1)
        max_str = ""

        for i in range(len(word)):
            end = min(i + max_len, len(word))
            substr = word[i:end]
            if substr > max_str:
                max_str = substr

        return max_str

# Test case
if __name__ == "__main__":
    solution =Solution();
    # case 1
    word1 = "dbca"
    numFriends1 = 2
    print(f"Result of test case 1: {solution.answerString(word1, numFriends1)}") # Expected output: dbc
    # case 2
    word2 = "gggg"
    numFriends2 = 4
    print(f"Result of test case 2: {solution.answerString(word2, numFriends2)}") # Expected output: g