# 📋 Stone Game

## 💡 Intuition and Approach:
The problem presents a game theory scenario where Alice and Bob are playing optimally, with Alice starting first. The key to solving this problem lies in understanding that Alice, starting first and playing optimally, will always have a winning strategy. Here’s why:

1.  Even Number of Piles: Since the number of piles is even, Alice can always ensure that she gets either all the even-indexed or all the odd-indexed piles, whichever gives her the maximum number of stones.

2.  Odd Total of Stones: The total number of stones is odd, meaning that it's impossible for Alice and Bob to tie. Since Alice plays first and has the first choice to secure a better outcome, she can always force a win if she plays optimally.

Given these conditions, Alice can always win the game by making optimal choices, regardless of Bob's strategy.

Thus, the solution to this problem is simply to return True, indicating that Alice will always win when both play optimally.
# Code python[]
```python3 []
class Solution:
    def stoneGame(self, piles):
        return True
```
```C++ []
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};
```
```C []
bool stoneGame(int* piles, int pilesSize) {
    return true;
}
```
```js []
function stoneGame(piles) {
    return true;
}
```
