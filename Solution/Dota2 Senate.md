# 📜 Dota2 Senate

## 💡 Intuition
In the senate game, each senator from the Radiant or Dire party can ban one senator from the opposing party. The objective is to predict which party will have the majority at the end. By using queues to keep track of the indices of Radiant and Dire senators, we can simulate the banning process efficiently. The senator with the lower index bans the opponent with the higher index, and the winner re-enters the queue to potentially ban again in subsequent rounds.


# 🛠️ Approach
1.  Initialize Queues: Create two queues, radiant and dire, to store the indices of the senators from each party.
 
2.  Populate Queues: Iterate through the senate string and add the indices of 'R' to the radiant queue and 'D' to the dire queue.
 
3.  Simulate Rounds:
While both queues are non-empty, pop the front element from each queue (the indices of the current Radiant and Dire senators).
Compare the indices:
3.1 The senator with the lower index bans the opponent with the higher index.
3.2 The winner re-enters their respective queue with their index incremented by the length of the senate string (to simulate their return in the next round).

4.  Determine Winner: The game ends when one of the queues is empty. The remaining non-empty queue indicates the winning party.

# ⏰ Complexity
- Time complexity:
O(n), where n is the length of the senate string. Each senator can be added and removed from the queue at most twice.

- Space complexity:
O(n), as we store indices of all senators in the queues.

# 💻 Code
```python []
class Solution(object):
    def predictPartyVictory(self, senate):
        radiant = deque()
        dire = deque()

        for i, s in enumerate(senate):
            if s == 'R':
                radiant.append(i)
            else:
                dire.append(i)

        n = len(senate)

        while radiant and dire:
            r = radiant.popleft()
            d = dire.popleft()
            
            if r < d:
                radiant.append(r + n)
            else:
                dire.append(d + n)
        
        return "Radiant" if radiant else "Dire"
```
```C++ []
class Solution {
public:
    std::string predictPartyVictory(std::string senate) {
        std::queue<int> radiant, dire;

        for (int i = 0; i < senate.size(); ++i) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }

        int n = senate.size();

        while (!radiant.empty() && !dire.empty()) {
            int r = radiant.front();
            int d = dire.front();
            radiant.pop();
            dire.pop();

            if (r < d) {
                radiant.push(r + n);
            } else {
                dire.push(d + n);
            }
        }

        return radiant.empty() ? "Dire" : "Radiant";
    }
};
```
``` C []
typedef struct {
    int* data;
    int front;
    int rear;
    int capacity;
} Queue;

void initQueue(Queue* q, int capacity) {
    q->data = (int*)malloc(capacity * sizeof(int));
    q->front = 0;
    q->rear = 0;
    q->capacity = capacity;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, int value) {
    q->data[q->rear++] = value;
}

int dequeue(Queue* q) {
    return q->data[q->front++];
}

void freeQueue(Queue* q) {
    free(q->data);
}

char* predictPartyVictory(char* senate) {
    int n = strlen(senate);
    Queue radiant, dire;
    initQueue(&radiant, n);
    initQueue(&dire, n);

    for (int i = 0; i < n; ++i) {
        if (senate[i] == 'R') {
            enqueue(&radiant, i);
        } else {
            enqueue(&dire, i);
        }
    }

    while (!isEmpty(&radiant) && !isEmpty(&dire)) {
        int r = dequeue(&radiant);
        int d = dequeue(&dire);

        if (r < d) {
            enqueue(&radiant, r + n);
        } else {
            enqueue(&dire, d + n);
        }
    }

    char* result = (char*)malloc(8 * sizeof(char));
    if (!isEmpty(&radiant)) {
        strcpy(result, "Radiant");
    } else {
        strcpy(result, "Dire");
    }

    freeQueue(&radiant);
    freeQueue(&dire);

    return result;
}
```