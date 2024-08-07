# 📜 Integer to English Words


## 💡 Intuition
1.  Modular Approach:
    The main function (numberToWords) breaks the problem into manageable chunks of 1000. This makes it easier to handle the varying suffixes for thousands, millions, and billions.
    The helper function is a recursive function that handles numbers within each chunk, making it easier to manage the English word representation for numbers less than 1000.

2.  Handling Edge Cases:
    Special handling for zero ensures the function correctly returns "Zero" instead of an empty string or invalid result.
    Trimming trailing spaces ensures the final result is clean and properly formatted.

3.  Readability and Maintainability:
    Using arrays for words (less_than_20, tens, thousands) makes the code more readable and easier to maintain.
    The separation of concerns between the main function and the helper function makes the code modular and easier to understand.

## 🛠️ Approach
1.  Initialization:
    The constructor initializes three arrays:
        less_than_20: Contains English words for numbers from 0 to 19.
        tens: Contains English words for multiples of ten from 10 to 90.
        thousands: Contains English words for the thousands, millions, and billions place.

2.  Number to Words Conversion (numberToWords method):
    Handle the special case where the input number is 0 by returning "Zero".
    Iterate over the thousands array to process the number in chunks of thousands (1000, 1,000,000, 1,000,000,000).
    For each chunk, if the chunk is non-zero, convert it to words using the helper method and append the appropriate thousand, million, or billion suffix.
    Assemble the final result by concatenating the words with the appropriate suffixes in reverse order.
    Remove any trailing spaces from the result before returning it.

3.  Helper Method (helper):
    This method recursively converts a number less than 1000 into words.
    It handles three cases:
        Numbers less than 20: Directly return the corresponding word from less_than_20.
        Numbers less than 100: Use the tens array for the tens place and recursively call helper for the units place.
        Numbers 100 and above: Convert the hundreds place and recursively call helper for the remainder.

## ⏰ Complexity
- Time complexity:
O(N), where N is the number of digits in the input number. The conversion processes each digit once, making it linear in terms of the number of digits.

- Space complexity:
O(1) for the fixed size of the arrays storing words. The recursive calls in the helper function use space proportional to the depth of recursion, which in the worst case is O(log N) due to the recursive processing of digits.

## 💻 Code
```python []
class Solution:
    def __init__(self):
        self.less_than_20 = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                             "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
                             "Nineteen"]
        self.tens = ["", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
        self.thousands = ["", "Thousand", "Million", "Billion"]
    
    def numberToWords(self, num: int) -> str:
        if num == 0:
            return "Zero"
        
        res = ''
        for i in range(len(self.thousands)):
            if num % 1000 != 0:
                res = self.helper(num % 1000) + self.thousands[i] + ' ' + res
            num //= 1000
        
        return res.strip()
    
    def helper(self, num: int) -> str:
        if num == 0:
            return ''
        elif num < 20:
            return self.less_than_20[num] + ' '
        elif num < 100:
            return self.tens[num // 10] + ' ' + self.helper(num % 10)
        else:
            return self.less_than_20[num // 100] + ' Hundred ' + self.helper(num % 100)
```
```c++ []
class Solution {
public:
    Solution() {
        less_than_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
                        "Nineteen"};
        tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        thousands = {"", "Thousand", "Million", "Billion"};
    }
    
    std::string numberToWords(int num) {
        if (num == 0) return "Zero";
        
        std::string res;
        for (int i = 0; i < thousands.size() && num > 0; ++i) {
            if (num % 1000 != 0) {
                res = helper(num % 1000) + thousands[i] + " " + res;
            }
            num /= 1000;
        }
        
        while (!res.empty() && res.back() == ' ') {
            res.pop_back(); 
        }
        
        return res;
    }

private:
    std::vector<std::string> less_than_20;
    std::vector<std::string> tens;
    std::vector<std::string> thousands;
    std::string helper(int num) {
        if (num == 0) return "";
        else if (num < 20) return less_than_20[num] + " ";
        else if (num < 100) return tens[num / 10] + " " + helper(num % 10);
        else return less_than_20[num / 100] + " Hundred " + helper(num % 100);
    }
};
```