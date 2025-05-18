# 📜 Sort Colors

## 💡 Intuition

This problem is a classic example of the **Dutch National Flag algorithm**. The idea is to sort an array that only contains 0s, 1s, and 2s in a single pass and **in-place**.
Think of 0s as red, 1s as white, and 2s as blue — we want to group the colors in the correct order: red, white, then blue.

To achieve this efficiently, we can maintain three pointers:

* One for the **next position of red (0)** — let's call it `red`
* One for the **current element being checked** — `white`
* One for the **next position of blue (2)** — `blue`

## 🛠️ Approach

We traverse the array with the `white` pointer, and:

* If we find a `0`, swap it with the element at the `red` pointer, and move both `red` and `white` forward.
* If we find a `1`, just move `white` forward.
* If we find a `2`, swap it with the element at the `blue` pointer, and move `blue` backward. But don't move `white`, because the swapped value could be 0, 1, or 2, and needs to be processed.

This way, we guarantee:

* All elements before `red` are 0
* All elements between `red` and `white` are 1
* All elements after `blue` are 2

This is done **in one pass** and **without extra space**.

## ⏰ Complexity

* **Time complexity:** `O(n)` — We scan the array only once with constant-time operations.
* **Space complexity:** `O(1)` — We use only a few integer variables; no extra space is required.

---

## 💻 Code
```C []
void sortColors(int* nums, int numsSize) {
    int red = 0, white = 0, blue = numsSize - 1;
    
    while (white <= blue) {
        if (nums[white] == 0) {
            int temp = nums[white];
            nums[white] = nums[red];
            nums[red] = temp;
            red++;
            white++;
        } else if (nums[white] == 1) {
            white++;
        } else {
            int temp = nums[white];
            nums[white] = nums[blue];
            nums[blue] = temp;
            blue--;
        }
    }
}
```
```C++ []
class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int red = 0, white = 0, blue = nums.size() - 1;
        while (white <= blue) {
            if (nums[white] == 0) {
                std::swap(nums[white], nums[red]);
                red++;
                white++;
            } else if (nums[white] == 1) {
                white++;
            } else {
                std::swap(nums[white], nums[blue]);
                blue--;
            }
        }
    }
};
```
```java []
public class Solution {
    public void sortColors(int[] nums) {
        int red = 0, white = 0, blue = nums.length - 1;

        while (white <= blue) {
            if (nums[white] == 0) {
                int temp = nums[white];
                nums[white] = nums[red];
                nums[red] = temp;
                red++;
                white++;
            } else if (nums[white] == 1) {
                white++;
            } else {
                int temp = nums[white];
                nums[white] = nums[blue];
                nums[blue] = temp;
                blue--;
            }
        }
    }
}
```
```Python []
class Solution:
    def sortColors(self, nums):
        red, white, blue = 0, 0, len(nums) - 1
        while white <= blue:
            if nums[white] == 0:
                nums[red], nums[white] = nums[white], nums[red]
                red += 1
                white += 1
            elif nums[white] == 1:
                white += 1
            else:
                nums[white], nums[blue] = nums[blue], nums[white]
                blue -= 1
```