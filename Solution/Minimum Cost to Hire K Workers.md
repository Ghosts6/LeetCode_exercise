# Minimum Cost to Hire K Workers

## 📜 Problem Description
Given `n` workers represented by their qualities and minimum wage expectations, this algorithm aims to hire exactly `k` workers to form a paid group. The group must adhere to the following rules:
- Each worker must be paid at least their minimum wage expectation.
- Within the group, each worker's pay must be proportional to their quality.

## 🛠️Approach
1. Calculate the wage to quality ratio for each worker and sort them in ascending order of ratio.
2. Initialize variables: `minCost` to track the minimum cost, `qualitySum` to track the total quality of the selected workers, and a max heap to maintain the highest quality workers.
3. Iterate through the sorted workers:
   - Add the worker's quality to `qualitySum`.
   - Push the quality of the worker to the max heap.
   - If the size of the max heap exceeds `k`, pop the highest quality worker from the heap and subtract their quality from `qualitySum`.
   - If the size of the max heap equals `k`, update `minCost` with the minimum of the current cost and the ratio multiplied by the total quality.
4. Return `minCost`.

### 💡Intuition
The algorithm sorts workers by their wage to quality ratio. It then iterates through the sorted workers, maintaining a maximum heap of worker qualities. At each step, it calculates the total quality sum of the group and updates the minimum cost if the group size equals `k`.

### ⏰Complexity
- Time Complexity: O(n log n) for sorting the workers and building the heap.
- Space Complexity: O(n) for storing the heap and other variables.

# 💻 Code
### c++
```c++
class Solution {
public:
    double mincostToHireWorkers(std::vector<int>& quality, std::vector<int>& wage, int k) {
        int n = quality.size();
        std::vector<std::pair<double, int>> ratioQuality;
        for (int i = 0; i < n; ++i) {
            ratioQuality.push_back({(double)wage[i] / quality[i], i});
        }
        std::sort(ratioQuality.begin(), ratioQuality.end());
        std::priority_queue<int> maxHeap;
        double minCost = std::numeric_limits<double>::max();
        double qualitySum = 0;
        for (auto [ratio, index] : ratioQuality) {
            qualitySum += quality[index];
            maxHeap.push(quality[index]);

            if (maxHeap.size() > k) {
                qualitySum -= maxHeap.top();
                maxHeap.pop();
            }
            if (maxHeap.size() == k) {
                minCost = std::min(minCost, ratio * qualitySum);
            }
        }
        return minCost;
    }
};
```
### python
```python
class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:
        n = len(quality)
        ratio_quality = [(wage[i] / quality[i], i) for i in range(n)]
        ratio_quality.sort()
        max_heap = []
        min_cost = float('inf')
        quality_sum = 0
        
        for ratio, index in ratio_quality:
            quality_sum += quality[index]
            heapq.heappush(max_heap, -quality[index])
            if len(max_heap) > k:
                quality_sum += heapq.heappop(max_heap)
            if len(max_heap) == k:
                min_cost = min(min_cost, ratio * quality_sum)

        return min_cost
```
### java scirpt
```javascript
var mincostToHireWorkers = function(quality, wage, k) {
    const n = quality.length;
    const ratioQuality = [];
    for (let i = 0; i < n; ++i) {
        ratioQuality.push([wage[i] / quality[i], quality[i]]);
    }
    ratioQuality.sort((a, b) => a[0] - b[0]);
    
    let minCost = Infinity;
    let qualitySum = 0;
    const maxHeap = new MaxHeap();

    for (let [ratio, q] of ratioQuality) {
        qualitySum += q;
        maxHeap.push(q);

        if (maxHeap.size() > k) {
            qualitySum -= maxHeap.pop();
        }

        if (maxHeap.size() === k) {
            minCost = Math.min(minCost, ratio * qualitySum);
        }
    }

    return minCost;
};

class MaxHeap {
    constructor() {
        this.heap = [];
    }

    size() {
        return this.heap.length;
    }

    push(val) {
        this.heap.push(val);
        this.heapifyUp(this.heap.length - 1);
    }

    pop() {
        if (this.heap.length === 0) return undefined;
        if (this.heap.length === 1) return this.heap.pop();
        const max = this.heap[0];
        this.heap[0] = this.heap.pop();
        this.heapifyDown(0);
        return max;
    }

    heapifyUp(index) {
        let currentIndex = index;
        while (currentIndex > 0) {
            const parentIndex = Math.floor((currentIndex - 1) / 2);
            if (this.heap[currentIndex] <= this.heap[parentIndex]) break;
            [this.heap[currentIndex], this.heap[parentIndex]] = [this.heap[parentIndex], this.heap[currentIndex]];
            currentIndex = parentIndex;
        }
    }

    heapifyDown(index) {
        let currentIndex = index;
        while (true) {
            const leftChildIndex = 2 * currentIndex + 1;
            const rightChildIndex = 2 * currentIndex + 2;
            let largestIndex = currentIndex;
            if (leftChildIndex < this.heap.length && this.heap[leftChildIndex] > this.heap[largestIndex]) {
                largestIndex = leftChildIndex;
            }
            if (rightChildIndex < this.heap.length && this.heap[rightChildIndex] > this.heap[largestIndex]) {
                largestIndex = rightChildIndex;
            }
            if (largestIndex === currentIndex) break;
            [this.heap[currentIndex], this.heap[largestIndex]] = [this.heap[largestIndex], this.heap[currentIndex]];
            currentIndex = largestIndex;
        }
    }
}
```