import heapq
from typing import List

class TaskManager:
    def __init__(self, tasks: List[List[int]] = []):
        self.heap = []  # stores (-priority, -taskId, userId)
        self.task_map = {}  # taskId -> (priority, userId)
        for userId, taskId, priority in tasks:
            self.add(userId, taskId, priority)

    def add(self, userId: int, taskId: int, priority: int) -> None:
        self.task_map[taskId] = (priority, userId)
        heapq.heappush(self.heap, (-priority, -taskId, userId))

    def edit(self, taskId: int, newPriority: int) -> None:
        if taskId not in self.task_map:
            return
        userId = self.task_map[taskId][1]
        self.task_map[taskId] = (newPriority, userId)
        heapq.heappush(self.heap, (-newPriority, -taskId, userId))

    def rmv(self, taskId: int) -> None:
        if taskId in self.task_map:
            del self.task_map[taskId]  # lazy removal

    def execTop(self) -> int:
        while self.heap:
            priority, neg_taskId, userId = heapq.heappop(self.heap)
            taskId = -neg_taskId
            if taskId in self.task_map and self.task_map[taskId][0] == -priority:
                # valid task
                del self.task_map[taskId]
                return userId
        return -1


# Test cases
if __name__ == "__main__":
    # Example 1
    sol = TaskManager([[1, 101, 10], [2, 102, 20], [3, 103, 15]])
    sol.add(4, 104, 5)
    sol.edit(102, 8)
    print(sol.execTop())  # Expected 3 (task 103)
    sol.rmv(101)
    sol.add(5, 105, 15)
    print(sol.execTop())  # Expected 5 (task 105)

    # Additional cases
    sol2 = TaskManager()
    print(sol2.execTop())  # Expected -1 (empty)
    sol2.add(1, 201, 50)
    sol2.add(2, 202, 50)
    print(sol2.execTop())  # Expected 2 (higher taskId)
    sol2.edit(201, 60)
    print(sol2.execTop())  # Expected 1 (higher priority)

