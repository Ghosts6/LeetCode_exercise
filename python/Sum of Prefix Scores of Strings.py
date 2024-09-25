from typing import List

class TrieNode:
    def __init__(self):
        self.children = {}
        self.score = 0  

class Solution:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
            node.score += 1  

    def getScore(self, word: str) -> int:
        node = self.root
        total_score = 0
        for char in word:
            if char in node.children:
                node = node.children[char]
                total_score += node.score  
        return total_score

    def sumPrefixScores(self, words: List[str]) -> List[int]:
        for word in words:
            self.insert(word)
        
        result = []
        for word in words:
            result.append(self.getScore(word))
        return result

# Test cases
solution = Solution()

# case 1
words1 = ["abc","ab","bc","b"]
print(solution.sumPrefixScores(words1))  # Output: [5, 4, 3, 2]

# case 2
words2 = ["abcd"]
print(solution.sumPrefixScores(words2))  # Output: [4]
