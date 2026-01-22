#include <stdio.h>

#define max 5

typedef struct {
    int data[max];
    int front;
    int rear;
    int count;
} queue;

void init(queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int isEmpty(queue *q) {
    return q->count == 0;
}

int isFull(queue *q) {
    return q->count == max;
}

void enqueue(queue *q, int value) {
    if (isFull(q)) {
        printf("queue penuh\n");
        return;
    }

    q->rear = (q->rear + 1) % max;
    q->data[q->rear] = value;
    q->count++;

    printf("enqueue: %d\n", value);
}

int dequeue(queue *q) {
    if (isEmpty(q)) {
        printf("queue kosong\n");
        return -1;
    }

    int value = q->data[q->front];
    q->front = (q->front + 1) % max;
    q->count--;

    printf("dequeue: %d\n", value);
    return value;
}

int front(queue *q) {
    if (isEmpty(q)) return -1;
    return q->data[q->front];
}

int rear(queue *q) {
    if (isEmpty(q)) return -1;
    return q->data[q->rear];
}

void display(queue *q){
    if (isEmpty(q)){
        printf("queue kosong\n");
        return;
    }
    printf("isi queue: ");
    int i = q->front;
    for (int k = 0; k < q->count; k++){
        printf("%d ", q->data[i]);

        i = (i + 1) % max;
    }
    printf("\n");
}

int main() {
    queue q;
    init(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    return 0;
}
