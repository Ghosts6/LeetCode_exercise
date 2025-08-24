from typing import List

class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        n = len(baskets)
        size = 1
        while size < n:
            size <<= 1
        NEG = -10**18
        tree = [NEG] * (2 * size)
        for i, cap in enumerate(baskets):
            tree[size + i] = cap
        for i in range(size - 1, 0, -1):
            tree[i] = tree[2 * i] if tree[2 * i] >= tree[2 * i + 1] else tree[2 * i + 1]

        def update(pos: int, val: int) -> None:
            i = size + pos
            tree[i] = val
            i //= 2
            while i:
                tree[i] = tree[2 * i] if tree[2 * i] >= tree[2 * i + 1] else tree[2 * i + 1]
                i //= 2

        def first_at_least(x: int) -> int:
            if tree[1] < x:
                return -1
            i = 1
            while i < size:
                left = 2 * i
                if tree[left] >= x:
                    i = left
                else:
                    i = left + 1
            return i - size  

        unplaced = 0
        for f in fruits:
            idx = first_at_least(f)
            if idx == -1:
                unplaced += 1
            else:
                update(idx, NEG) 
        return unplaced

# Test cases
if __name__ == "__main__":
    solver = Solution()
    
    fruits1, baskets1 = [4, 2, 5], [3, 5, 4]
    print(f"Test case 1 : {solver.numOfUnplacedFruits(fruits1, baskets1)}")  # Expected 1
    
    fruits2, baskets2 = [3, 6, 1], [6, 4, 7]
    print(f"Test case 2 : {solver.numOfUnplacedFruits(fruits2, baskets2)}")  # Expected 0

