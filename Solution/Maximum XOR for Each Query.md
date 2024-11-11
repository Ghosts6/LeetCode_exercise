# 📜 **Maximum XOR for Each Query**

## 💡 **Intuition**

The problem asks us to calculate the maximum XOR of a given list of integers with respect to a number defined by the maximum number of bits (`maximumBit`). A key insight here is that we can use the total XOR of all elements in the array and adjust it iteratively as we move through the array. By doing this, we can quickly calculate the result for each query in an efficient way.

- **XOR Basics:** XOR is a bitwise operation where identical bits cancel each other out (1 ^ 1 = 0, 0 ^ 0 = 0) and different bits give 1 (1 ^ 0 = 1). This makes it very useful for toggling bits and finding relationships between numbers.
  
- **Total XOR:** The idea behind using the total XOR of the array is to reduce the problem complexity, so we don’t need to calculate the XOR for every query individually.

- **Masking:** By using a bitmask (`(1 << maximumBit) - 1`), we can ensure that the XOR values are bounded within the range of the maximum number of bits specified by the problem.

## 🛠️ **Approach**

1. **Initial XOR Calculation:** 
   - First, calculate the XOR of all the numbers in the array. This gives us a starting point for calculating the XOR values for each query.

2. **Bit Masking:**
   - The bitmask helps in constraining the XOR result to the `maximumBit` range, ensuring we only consider the relevant bits.

3. **Iterative XOR Adjustment:**
   - As we iterate through the array in reverse order, we adjust the total XOR by removing the effect of the current number using `totalXor ^= nums[n - 1 - i]`. This efficiently updates the XOR for each query.
   
4. **Return Result:**
   - For each query, the result is simply the XOR of the total XOR and the bitmask (`totalXor ^ mask`).

## ⏰ **Complexity**

- **Time complexity:**  
  The time complexity is \(O(n)\), where \(n\) is the size of the input array. This is because we iterate over the array only a few times (once for total XOR calculation and once for the final results).

- **Space complexity:**  
  The space complexity is \(O(n)\), where \(n\) is the number of elements in the input array. This is due to the storage of the result array.

## 💻 **Code**
```c++ []
class Solution {
public:
    std::vector<int> getMaximumXor(std::vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int totalXor = 0;
        for (int num : nums) {
            totalXor ^= num;
        }
        
        int mask = (1 << maximumBit) - 1;
        std::vector<int> answer(n);
        
        for (int i = 0; i < n; ++i) {
            answer[i] = totalXor ^ mask;
            totalXor ^= nums[n - 1 - i];
        }
        
        return answer;
    }
};
```
```python3 []
class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        n = len(nums)
        totalXor = 0

        for num in nums:
            totalXor ^= num
        
        mask = (1 << maximumBit) - 1
        answer = [0] * n
 
        for i in range(n):
            answer[i] = totalXor ^ mask
            totalXor ^= nums[n - 1 - i]
        
        return answer
```
```js []
var getMaximumXor = function (nums, maximumBit) {
    const n = nums.length;
    let totalXor = 0;

    for (let num of nums) {
        totalXor ^= num;
    }

    const mask = (1 << maximumBit) - 1; 
    const answer = new Array(n);

    for (let i = 0; i < n; i++) {
        answer[i] = totalXor ^ mask;
        totalXor ^= nums[n - 1 - i];
    }

    return answer;
}
```