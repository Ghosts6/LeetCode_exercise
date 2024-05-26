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