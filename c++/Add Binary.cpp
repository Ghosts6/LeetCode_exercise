class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string result;
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            result = std::to_string(sum % 2) + result;
            carry = sum / 2;
        }

        return result;
    }
};