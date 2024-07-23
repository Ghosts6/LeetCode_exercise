class Solution:
    def canVisitAllRooms(self, rooms):
        visited = set()
        self.dfs(rooms, 0, visited)
        return len(visited) == len(rooms)

    def dfs(self, rooms, room, visited):
        visited.add(room)
        for key in rooms[room]:
            if key not in visited:
                self.dfs(rooms, key, visited)

# Test case
if __name__ == "__main__":
    solution = Solution()
    rooms = [[1], [2], [3], []]
    result = solution.canVisitAllRooms(rooms)
    print("Can visit all rooms:", result)  

    rooms = [[1, 3], [3, 0, 1], [2], [0]]
    result = solution.canVisitAllRooms(rooms)
    print("Can visit all rooms:", result)  
