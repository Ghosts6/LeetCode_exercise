#include <stdio.h>
#include <stdlib.h>

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

// Test case
int main() {
    int grid1[3][3] = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    int* gridPtrs1[3] = {grid1[0], grid1[1], grid1[2]};
    int gridColSize1[3] = {3, 3, 3};
    int result1 = orangesRotting(gridPtrs1, 3, gridColSize1);
    printf("Test case : %d\n", result1); 

    return 0;
}
