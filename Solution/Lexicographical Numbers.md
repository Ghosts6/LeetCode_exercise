# 📜 Lexicographical Numbers


## 💡 Intuition
Lexicographical order sorts numbers as if they were strings in a dictionary. For example, the order is:  
`1, 10, 100, 101, ..., 11, 12, ..., 2, 20, 21, ...`.

Instead of converting numbers to strings and sorting (which is slow), we can simulate this order by traversing a tree where:
- Each node represents a number.
- The children of a node `x` are `x*10, x*10+1, ..., x*10+9`.

This can be done iteratively by moving deeper into the tree (`x*10`) or moving to the next sibling (`x+1`), while making sure we don’t exceed `n`.

## 🛠️ Approach
1. Start from `current = 1`.
2. At each step, add `current` to the result.
3. If `current * 10 <= n`, move to the next depth (`current *= 10`).
4. Else, if `current + 1 <= n` and the last digit is not 9, increment (`current++`).
5. Otherwise, move up the tree (`current /= 10`) until you can increment again.

This simulates a pre-order traversal of the lexicographical tree.

## ⏰ Complexity
- **Time complexity:** `O(n)`  
  We visit each number from `1` to `n` exactly once.

- **Space complexity:** `O(1)` (excluding the output array)  
  We use constant space for control variables. Output array requires `O(n)`.


## 💻 Code
```c []
int* lexicalOrder(int n, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * n);
    int index = 0;
    int current = 1;

    while (index < n) {
        result[index++] = current;
        
        if (current * 10 <= n) {
            current *= 10;
        } else {
            while (current % 10 == 9 || current + 1 > n) {
                current /= 10;
            }
            current++;
        }
    }

    *returnSize = n;
    return result;
}
```
```C++ []
class Solution {
public:
    std::vector<int> lexicalOrder(int n) {
        std::vector<int> result;
        int current = 1;
        for (int i = 0; i < n; ++i) {
            result.push_back(current);
            if (current * 10 <= n) {
                current *= 10;
            } else {
                if (current >= n) {
                    current /= 10;
                }
                current++;
                while (current % 10 == 0) {
                    current /= 10;
                }
            }
        }
        return result;
    }
};
```
```java []
class Solution {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> result = new ArrayList<>();
        int current = 1;

        for (int i = 0; i < n; ++i) {
            result.add(current);
            if (current * 10 <= n) {
                current *= 10;
            } else {
                if (current >= n) {
                    current /= 10;
                }
                current++;
                while (current % 10 == 0) {
                    current /= 10;
                }
            }
        }

        return result;
    }
}
```
```python3 []
class Solution:
    def lexicalOrder(self, n: int) -> list[int]:
        result = []
        current = 1
        
        for _ in range(n):
            result.append(current)
            if current * 10 <= n:
                current *= 10
            else:
                if current >= n:
                    current //= 10
                current += 1
                while current % 10 == 0:
                    current //= 10
                    
        return result
```
