# 📜 Second Minimum Time to Reach Destination


## 💡 Intuition
The problem can be visualized as a shortest path problem on a graph with additional constraints due to traffic signals. The goal is to find the second shortest path from vertex 1 to vertex n where path traversal is constrained by traffic signals that switch between green and red every change minutes.

## 🛠️ Approach
1.  Graph Representation: Use an adjacency list to represent the graph efficiently.
2.  Priority Queue: Use a min-heap (priority queue) to always expand the least time-consuming path first.
3.  State Management: Maintain the shortest and second shortest travel times to each vertex.
4.  Wait Time Calculation: Account for the traffic signals. If you arrive at a vertex while its signal is red, you need to wait until it turns green to proceed.
5.  Dijkstra-like Traversal: Adapt the Dijkstra algorithm to handle the constraints. Use a priority queue to manage states (current vertex and current travel time).

## ⏰ Complexity
- Time complexity:
The time complexity of the solution is O((E+V)logV), where E is the number of edges and V is the number of vertices

- Space complexity:
The space complexity of the solution is O(E+V) 

## 💻 Code
```c++ []
class Solution {
public:
    struct State {
        int node;
        int time;
        bool operator>(const State& other) const {
            return time > other.time;
        }
    };
    
    int secondMinimum(int n, std::vector<std::vector<int>>& edges, int time, int change) {
        std::vector<std::vector<int>> graph(n + 1);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        std::vector<int> minTime(n + 1, INT_MAX);
        std::vector<int> secondMinTime(n + 1, INT_MAX);
        std::priority_queue<State, std::vector<State>, std::greater<State>> pq;
        
        pq.push({1, 0});
        minTime[1] = 0;
        
        while (!pq.empty()) {
            State curr = pq.top();
            pq.pop();
            int currNode = curr.node;
            int currTime = curr.time;
            
            for (int neighbor : graph[currNode]) {
                int waitTime = 0;
                if ((currTime / change) % 2 == 1) {
                    waitTime = change - (currTime % change);
                }
                int nextTime = currTime + time + waitTime;
                
                if (nextTime < minTime[neighbor]) {
                    secondMinTime[neighbor] = minTime[neighbor];
                    minTime[neighbor] = nextTime;
                    pq.push({neighbor, nextTime});
                } else if (nextTime > minTime[neighbor] && nextTime < secondMinTime[neighbor]) {
                    secondMinTime[neighbor] = nextTime;
                    pq.push({neighbor, nextTime});
                }
            }
        }
        
        return secondMinTime[n];
    }
};
```
```c []
typedef struct {
    int node;
    int time;
} State;

typedef struct {
    State* data;
    int size;
    int capacity;
} MinHeap;

void swap(State* a, State* b) {
    State temp = *a;
    *a = *b;
    *b = temp;
}

MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->data = (State*)malloc(capacity * sizeof(State));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->data[left].time < heap->data[smallest].time)
        smallest = left;

    if (right < heap->size && heap->data[right].time < heap->data[smallest].time)
        smallest = right;

    if (smallest != idx) {
        swap(&heap->data[idx], &heap->data[smallest]);
        minHeapify(heap, smallest);
    }
}

State extractMin(MinHeap* heap) {
    if (heap->size <= 0)
        return (State){-1, -1};
    
    if (heap->size == 1) {
        heap->size--;
        return heap->data[0];
    }

    State root = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);

    return root;
}

void insertMinHeap(MinHeap* heap, State k) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->data = (State*)realloc(heap->data, heap->capacity * sizeof(State));
    }

    heap->size++;
    int i = heap->size - 1;
    heap->data[i] = k;

    while (i != 0 && heap->data[(i - 1) / 2].time > heap->data[i].time) {
        swap(&heap->data[i], &heap->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void freeMinHeap(MinHeap* heap) {
    free(heap->data);
    free(heap);
}

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node** heads;
    int* sizes;
    int size;
} Graph;

Graph* createGraph(int n) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->heads = (Node**)malloc((n + 1) * sizeof(Node*));
    graph->sizes = (int*)calloc(n + 1, sizeof(int));
    graph->size = n;

    for (int i = 0; i <= n; i++) {
        graph->heads[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int u, int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = v;
    node->next = graph->heads[u];
    graph->heads[u] = node;

    node = (Node*)malloc(sizeof(Node));
    node->val = u;
    node->next = graph->heads[v];
    graph->heads[v] = node;

    graph->sizes[u]++;
    graph->sizes[v]++;
}

void freeGraph(Graph* graph) {
    for (int i = 0; i <= graph->size; i++) {
        Node* head = graph->heads[i];
        while (head) {
            Node* temp = head;
            head = head->next;
            free(temp);
        }
    }
    free(graph->heads);
    free(graph->sizes);
    free(graph);
}

int secondMinimum(int n, int** edges, int edgesSize, int* edgesColSize, int time, int change) {
    Graph* graph = createGraph(n);
    for (int i = 0; i < edgesSize; i++) {
        addEdge(graph, edges[i][0], edges[i][1]);
    }

    int* minTime = (int*)malloc((n + 1) * sizeof(int));
    int* secondMinTime = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        minTime[i] = INT_MAX;
        secondMinTime[i] = INT_MAX;
    }

    MinHeap* pq = createMinHeap(edgesSize * 2);
    insertMinHeap(pq, (State){1, 0});
    minTime[1] = 0;

    while (pq->size > 0) {
        State curr = extractMin(pq);
        int currNode = curr.node;
        int currTime = curr.time;

        Node* neighborNode = graph->heads[currNode];
        while (neighborNode) {
            int neighbor = neighborNode->val;
            int waitTime = 0;
            if ((currTime / change) % 2 == 1) {
                waitTime = change - (currTime % change);
            }
            int nextTime = currTime + time + waitTime;

            if (nextTime < minTime[neighbor]) {
                secondMinTime[neighbor] = minTime[neighbor];
                minTime[neighbor] = nextTime;
                insertMinHeap(pq, (State){neighbor, nextTime});
            } else if (nextTime > minTime[neighbor] && nextTime < secondMinTime[neighbor]) {
                secondMinTime[neighbor] = nextTime;
                insertMinHeap(pq, (State){neighbor, nextTime});
            }

            neighborNode = neighborNode->next;
        }
    }

    int result = secondMinTime[n];
    free(minTime);
    free(secondMinTime);
    freeMinHeap(pq);
    freeGraph(graph);

    return result;
}

```