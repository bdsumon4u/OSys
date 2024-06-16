#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *next;
    int data;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

struct Node *createNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue *queue, int data)
{
    struct Node *node = createNode(data);
    if (queue->front) {
        queue->front->next = node;
    } else {
        queue->rear = node;
    }
    queue->front = node;
}

int dequeue(struct Queue *queue)
{
    if (queue->rear == NULL) {
        return -1;
    } else {
        struct Node *node = queue->rear;
        queue->rear = queue->rear->next;
        int data = node->data;
        free(node);
        return data;
    }
}

void main(int argc, char const *argv[])
{
    struct Queue *queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    enqueue(queue, 40);
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));

    exit(EXIT_SUCCESS);
}
