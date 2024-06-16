#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *next;
    int data;
};

struct Stack {
    struct Node *head;
};

struct Node *createNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Stack *createStack() {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->head = NULL;
    return stack;
}

void push(struct Stack *stack, int data) {
    struct Node *node = createNode(data);
    node->next = stack->head;
    stack->head = node;
}

int pop(struct Stack *stack) {
    if (stack->head == NULL) {
        return -1;
    } else {
        struct Node *node = stack->head;
        stack->head = stack->head->next;
        int data = node->data;
        free(node);
        return data;
    }
}

void main(int argc, char const *argv[])
{
    struct Stack *stack = createStack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    push(stack, 40);
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));

    exit(EXIT_SUCCESS);
}
