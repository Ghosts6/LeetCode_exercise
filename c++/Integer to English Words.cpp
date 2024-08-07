#include <vector>
#include <string>
#include <iostream>

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
//  test case
int main() {
    Solution solution;
    std::vector<int> test_cases = {0, 13, 85, 123, 12345, 1234567, 1234567891};
    
    for (int num : test_cases) {
        std::cout << num << " -> " << solution.numberToWords(num) << std::endl;
    }

    return 0;
}
