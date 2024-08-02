# 📜 Rotting Oranges


## 💡 Intuition
The problem is essentially about finding the minimum time required to rot all the fresh oranges. This can be visualized as a Breadth-First Search (BFS) problem on a 2D grid where each orange (either fresh or rotten) is a node, and each adjacent (up, down, left, right) orange can be considered as a connected node.

## 🛠️ Approach
1.  Initialization:
Traverse the grid and count the number of fresh oranges.
Add all the initial positions of rotten oranges to a queue.

2.  BFS Traversal:
Use the queue to perform BFS. For each rotten orange, rot its adjacent fresh oranges and add those newly rotten oranges to the queue.
Each level of BFS represents one unit of time.

3.  Result Calculation:
After the BFS traversal, if there are no fresh oranges left, return the time taken. Otherwise, return -1 indicating not all oranges can rot.

## ⏰ Complexity
- Time complexity:
O(m×n).

- Space complexity:
O(m×n).

## 💻 Code
```python []
class Solution:
    def orangesRotting(self, grid):
        if not grid or not grid[0]:
            return -1

        m, n = len(grid), len(grid[0])
        queue = deque()
        fresh_oranges = 0

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    queue.append((i, j))
                elif grid[i][j] == 1:
                    fresh_oranges += 1

        if fresh_oranges == 0:
            return 0

        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        minutes_elapsed = 0

        while queue:
            minutes_elapsed += 1
            for _ in range(len(queue)):
                x, y = queue.popleft()
                for dx, dy in directions:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < m and 0 <= ny < n and grid[nx][ny] == 1:
                        grid[nx][ny] = 2
                        fresh_oranges -= 1
                        queue.append((nx, ny))

        return minutes_elapsed - 1 if fresh_oranges == 0 else -1
```
```c []
typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *data;
    int front, rear, size, capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->data = (Point*) malloc(queue->capacity * sizeof(Point));
    return queue;
}

int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int x, int y) {
    if (isFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear].x = x;
    queue->data[queue->rear].y = y;
    queue->size = queue->size + 1;
}

Point dequeue(Queue* queue) {
    Point item = {-1, -1}; 
    if (isEmpty(queue)) return item;
    item = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    if (gridSize == 0 || gridColSize[0] == 0) return -1;

    int m = gridSize, n = gridColSize[0];
    Queue* queue = createQueue(m * n);
    int fresh_oranges = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                enqueue(queue, i, j);
            } else if (grid[i][j] == 1) {
                fresh_oranges++;
            }
        }
    }

    if (fresh_oranges == 0) return 0;

    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int minutes_elapsed = 0;

    while (!isEmpty(queue)) {
        int size = queue->size;
        minutes_elapsed++;

        for (int i = 0; i < size; i++) {
            Point point = dequeue(queue);
            for (int d = 0; d < 4; d++) {
                int nx = point.x + directions[d][0];
                int ny = point.y + directions[d][1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    fresh_oranges--;
                    enqueue(queue, nx, ny);
                }
            }
        }
    }

    free(queue->data);
    free(queue);

    return fresh_oranges == 0 ? minutes_elapsed - 1 : -1;
}
```