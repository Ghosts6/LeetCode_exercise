#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    int finalValueAfterOperations(std::vector<std::string>& operations) {
        int ans = 0;
        for(int i = 0; i < operations.size(); i++) {
            if(operations[i] == "X++" || operations[i] == "++X") {
                ans++;
            } else if(operations[i] == "X--" || operations[i] == "--X") {
                ans--;
            } else {
                std::cout << "wrong input !" << std::endl;
            }
        }
        return ans;
    }
};