class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap;
        int longest_length = 0;
        int first_index = 0;         
        for (int i = 0; i < s.length(); ++i) {
            if (charIndexMap.find(s[i]) != charIndexMap.end() && charIndexMap[s[i]] >= first_index) {
                first_index = charIndexMap[s[i]] + 1;
            }
            charIndexMap[s[i]] = i;      
            longest_length = max(longest_length, i - first_index + 1); 
        }
        
        return longest_length;
    }
};