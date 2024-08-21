#include <iostream>
#include <vector>
#include <queue>

class KthLargest {
private:
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

public:
    KthLargest(int k, std::vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        if (minHeap.size() < k) {
            minHeap.push(val);
        } else if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }
};
//  Test cases
int main() {
    std::vector<int> nums = {4, 5, 8, 2};
    KthLargest kthLargest(3, nums);

    std::cout << kthLargest.add(3) << std::endl;  // Expected output: 4
    std::cout << kthLargest.add(5) << std::endl;  // Expected output: 5
    std::cout << kthLargest.add(10) << std::endl; // Expected output: 5
    std::cout << kthLargest.add(9) << std::endl;  // Expected output: 8
    std::cout << kthLargest.add(4) << std::endl;  // Expected output: 8

    return 0;
}
