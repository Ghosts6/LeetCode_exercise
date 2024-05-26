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