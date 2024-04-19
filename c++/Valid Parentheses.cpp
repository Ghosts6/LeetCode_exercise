class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                char topChar = st.top();
                if ((c == ')' && topChar != '(') || 
                    (c == ']' && topChar != '[') || 
                    (c == '}' && topChar != '{')) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};