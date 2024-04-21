class Solution {
public:
    std::string longest_common_prefix(std::vector<std::string>& strs) {
        if (strs.empty()) {
            return "";
        }
        std::string prefix = strs[0];
        for (const std::string& str : strs) {
            if (str.length() < prefix.length()) {
                prefix = str;
            }
        }
        for (const std::string& str : strs) {
            int i = 0;
            while (i < prefix.length() && prefix[i] == str[i]) {
                i++;
            }
            prefix = prefix.substr(0, i);
        }
        
        return prefix;
    }
};