import heapq

class Solution:
    def leftmostBuildingQueries(self, heights, queries):
        n, q = len(heights), len(queries)
        result = [-1] * q  
        deferred = [[] for _ in range(n)]  
        pq = []  

        for i in range(q):
            a, b = queries[i]
            if a > b:
                a, b = b, a  
            if a == b or heights[a] < heights[b]:
                result[i] = b 
            else:
                deferred[b].append((heights[a], i)) 

        for i in range(n):
            for query in deferred[i]: 
                heapq.heappush(pq, query)
            while pq and pq[0][0] < heights[i]: 
                result[pq[0][1]] = i
                heapq.heappop(pq)

        return result

# Test cases
if __name__ == "__main__":
    # case 1
    heights = [6, 4, 8, 5, 2, 7]
    queries = [[0, 1], [0, 3], [2, 4], [3, 4], [2, 2]]
    sol = Solution()
    print(sol.leftmostBuildingQueries(heights, queries))  # Output: [2, 5, -1, 5, 2]

    # case 2
    heights = [5, 3, 8, 2, 6, 1, 4, 6]
    queries = [[0, 7], [3, 5], [5, 2], [3, 0], [1, 6]]
    print(sol.leftmostBuildingQueries(heights, queries))  # Output: [7, 6, -1, 4, 6]


