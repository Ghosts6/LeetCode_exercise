#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;  
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }  
        return left;
    }
};
// test
int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    Solution sol;
    int result = sol.searchInsert(nums, target);
    cout<<"test :"<<result<<endl;
    return 0;
}
