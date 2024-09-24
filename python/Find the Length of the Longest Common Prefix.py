class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False

class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, number):
        node = self.root
        for digit in str(number):
            if digit not in node.children:
                node.children[digit] = TrieNode()
            node = node.children[digit]
        node.is_end = True

    def longest_common_prefix(self, number):
        node = self.root
        common_length = 0
        for digit in str(number):
            if digit in node.children:
                common_length += 1
                node = node.children[digit]
            else:
                break
        return common_length

class Solution:
    def longestCommonPrefix(self, arr1, arr2):
        trie = Trie()
        for num in arr1:
            trie.insert(num)
        
        max_length = 0
        for num in arr2:
            current_length = trie.longest_common_prefix(num)
            max_length = max(max_length, current_length)
        
        return max_length

# Test Cases
if __name__ == "__main__":
    # case 1
    arr1 = [1, 10, 100]
    arr2 = [1000]
    solution = Solution(arr1, arr2)
    assert solution.longestCommonPrefix() == 3, "Test case 1 failed"

    # case 2
    arr1 = [1, 2, 3]
    arr2 = [4, 4, 4]
    solution = Solution(arr1, arr2)
    assert solution.longestCommonPrefix() == 0, "Test case 2 failed"
    
    print("All test cases passed!")
