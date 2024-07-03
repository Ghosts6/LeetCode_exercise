#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
//  test case
int main() {
    char senate[] = "RDDRR";
    printf("result: %s\n", predictPartyVictory(senate));
    return 0;
}