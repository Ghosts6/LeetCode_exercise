class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtrack(digits, mapping, 0, "", result);
        return result;
    }
private:
    void backtrack(const string& digits, const vector<string>& mapping, int index, string current, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        int digit = digits[index] - '0';
        const string& letters = mapping[digit];
        for (char c : letters) {
            backtrack(digits, mapping, index + 1, current + c, result);
        }
    }
};