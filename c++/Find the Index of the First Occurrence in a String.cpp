#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n_size = haystack.size(), m_size = needle.size();
        if (m_size == 0) return 0;
        if (n_size < m_size) return -1;       
        for (int i = 0; i <= n_size - m_size; ++i) {
            int j = 0;
            while (j < m_size && haystack[i + j] == needle[j]) {
                ++j;
            }
            if (j == m_size) return i;
        }      
        return -1;
    }
};
// Test 
int main() {
    string haystack = "hello", needle = "world";
    Solution sol;
    int result = sol.strStr(haystack, needle);
    cout<<"test :"<<result<<endl;
    return 0;
}
