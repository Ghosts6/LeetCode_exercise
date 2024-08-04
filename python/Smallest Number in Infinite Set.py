import heapq

class SmallestInfiniteSet:

    def __init__(self):
        self.current = 1
        self.added_back = set()
        self.min_heap = []

    def popSmallest(self) -> int:
        if self.min_heap:
            smallest = heapq.heappop(self.min_heap)
            self.added_back.remove(smallest)
            return smallest
        else:
            smallest = self.current
            self.current += 1
            return smallest

    def addBack(self, num: int) -> None:
        if num < self.current and num not in self.added_back:
            heapq.heappush(self.min_heap, num)
            self.added_back.add(num)

# test case:
obj = SmallestInfiniteSet()
print(obj.popSmallest())  
obj.addBack(2)
print(obj.popSmallest())  
print(obj.popSmallest())  
