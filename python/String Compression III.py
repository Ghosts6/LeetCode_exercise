class Solution:
    def compressedString(self, word: str) -> str:
        comp = ""
        i = 0  
        
        while i < len(word):
            current_char = word[i]
            count = 0
            
            while i < len(word) and word[i] == current_char and count < 9:
                i += 1
                count += 1

            comp += str(count) + current_char
        
        return comp

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # case 1
    word1 = "abcde"
    print("Test Case 1:")
    print("Input:", word1)
    print("Output:", solution.compressedString(word1))  # output: "1a1b1c1d1e"
    
    # case 2
    word2 = "aaaaaaaaaaaaaabb"
    print("Test Case 2:")
    print("Input:", word2)
    print("Output:", solution.compressedString(word2))  # output: "9a5a2b"
