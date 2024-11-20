#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int takeCharacters(std::string s, int k) {
        int n = s.size();

        std::unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        if (freq['a'] < k || freq['b'] < k || freq['c'] < k) {
            return -1;
        }

        std::unordered_map<char, int> left_freq, right_freq;
        int left = 0, right = n - 1;
        int min_minutes = n + 1;

        int remaining_a = k, remaining_b = k, remaining_c = k;

        for (int left_taken = 0; left_taken <= n; ++left_taken) {
            if (left_taken > 0) {
                left_freq[s[left_taken - 1]]++;
            }

            while (right >= left_taken && (remaining_a > 0 || remaining_b > 0 || remaining_c > 0)) {
                char right_char = s[right];
                right_freq[right_char]++;
                right--;

                if (right_char == 'a' && remaining_a > 0) remaining_a--;
                if (right_char == 'b' && remaining_b > 0) remaining_b--;
                if (right_char == 'c' && remaining_c > 0) remaining_c--;
            }

            if (remaining_a == 0 && remaining_b == 0 && remaining_c == 0) {
                int total_minutes = left_taken + (n - 1 - right);
                min_minutes = std::min(min_minutes, total_minutes);
            }
        }

        return min_minutes == n + 1 ? -1 : min_minutes;
    }
};
// Test cases
int main() {
    Solution solution;
    // case 1
    std::string s1 = "aabaaaacaabc";
    int k1 = 2;
    std::cout << "Test case 1: " << solution.takeCharacters(s1, k1) << std::endl;

    // case 2
    std::string s2 = "a";
    int k2 = 1;
    std::cout << "Test case 2: " << solution.takeCharacters(s2, k2) << std::endl;

    // case 3 Edge case 
    std::string s3 = "aaaaaaa";
    int k3 = 3;
    std::cout << "Test case 3: " << solution.takeCharacters(s3, k3) << std::endl;

    return 0;
}
