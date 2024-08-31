class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end_of_word = False

class Trie:

    def __init__(self):
        """
        Initializes the trie object.
        """
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        """
        Inserts the string word into the trie.
        """
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end_of_word = True

    def search(self, word: str) -> bool:
        """
        Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
        """
        node = self.root
        for char in word:
            if char not in node.children:
                return False
            node = node.children[char]
        return node.is_end_of_word

    def startsWith(self, prefix: str) -> bool:
        """
        Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
        """
        node = self.root
        for char in prefix:
            if char not in node.children:
                return False
            node = node.children[char]
        return True


# Test Cases

def test_trie():
    trie = Trie()
  
    trie.insert("apple")
    assert trie.search("apple") == True, "Test 1 Failed"
    assert trie.search("app") == False, "Test 1 Failed"

    assert trie.startsWith("app") == True, "Test 2 Failed"

    trie.insert("app")
    assert trie.search("app") == True, "Test 3 Failed"
    
    print("All tests passed!")

test_trie()
