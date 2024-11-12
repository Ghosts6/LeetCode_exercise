from typing import List

class Solution:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        items.sort()
        max_beauty_at_price = []
        current_max_beauty = 0
        for price, beauty in items:
            current_max_beauty = max(current_max_beauty, beauty)
            max_beauty_at_price.append((price, current_max_beauty))
        
        indexed_queries = sorted((q, i) for i, q in enumerate(queries))
        result = [0] * len(queries)
        
        def binary_search(query_price):
            low, high = 0, len(max_beauty_at_price) - 1
            while low <= high:
                mid = (low + high) // 2
                if max_beauty_at_price[mid][0] <= query_price:
                    low = mid + 1
                else:
                    high = mid - 1
            return high

        for query_price, original_index in indexed_queries:
            idx = binary_search(query_price)
            if idx >= 0:
                result[original_index] = max_beauty_at_price[idx][1]
            else:
                result[original_index] = 0

        return result
# Test cases
if __name__ == "__main__":
    solution = Solution()
    # case 1
    items = [[1,2],[3,2],[2,4],[5,6],[3,5]]
    queries = [1,2,3,4,5,6]
    print(solution.maximumBeauty(items, queries))  # Output: [2,4,5,5,6,6]
    
    # case 2
    items = [[1,2],[1,2],[1,3],[1,4]]
    queries = [1]
    print(solution.maximumBeauty(items, queries))  # Output: [4]
    
    # case 3
    items = [[10,1000]]
    queries = [5]
    print(solution.maximumBeauty(items, queries))  # Output: [0]
