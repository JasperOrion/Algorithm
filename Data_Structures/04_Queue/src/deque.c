#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
双端队列的实现形式感觉和无头结点的双向链表相差不大,操作相当于头插和尾插,
*/
typedef struct DequeNode {
    int data;
    struct DequeNode *next;
    struct DequeNode *prev;
} DequeNode;

typedef struct Deque {
    DequeNode *front;
    DequeNode *rear;

    int size;
} Deque;
/*-------------结构操作--------------*/
Deque *createDeque();
bool isEmpty(Deque *deque);
void insertFront(Deque *deque, int data);
void insertRear(Deque *deque, int data);
int deleteFront(Deque *deque);
int deleteRear(Deque *deque);
void destroyDeque(Deque *deque);

// 创建双端队列的结点
DequeNode *createNode(int value) {
    DequeNode *newNode = (DequeNode *)malloc(sizeof(DequeNode));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
// 初始化双端队列
Deque *createDeque() {
    Deque *deque = (Deque *)malloc(sizeof(Deque));
    deque->front = NULL;
    deque->rear = NULL;
    deque->size = 0;
    return deque;
}
// 从前面插入元素
void insertFront(Deque *deque, int value) {
    DequeNode *newNode = createNode(value);
    if (!newNode) {
        printf("Deque is NULL!\n");
        return;
    }
    if (deque->front == NULL) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
    deque->size++;
}
void insertRear(Deque *deque, int value) {
    DequeNode *newNode = createNode(value);
    if (!newNode) {
        printf("Deque is NULL!\n");
        return;
    }
    if (deque->front == NULL) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        deque->rear->next = newNode;
        newNode->prev = deque->rear;
        deque->rear = newNode;
    }
    deque->size++;
}
// 从前面删除元素
int deleteFront(Deque *deque) {
    if (!deque) {
        printf("Deque is NULL!\n");
        return -1;
    }
    if (deque->front == NULL) {
        printf("队列为空\n");
        return -1;
    }
    int data = deque->front->data;
    DequeNode *temp = deque->front;
    deque->front = deque->front->next;
    if (deque->front)
        deque->front->prev = NULL;
    else
        deque->rear = NULL;
    free(temp);
    deque->size--;
    return data;
}
/*因为双端队列由双向链表实现,首位删除操作相似*/
// 从后面删除元素
int deleteRear(Deque *deque) {
    if (!deque) {
        printf("Deque is NULL!\n");
        return -1;
    }
    if (deque->rear == NULL) {
        printf("队列为空\n");
        return -1;
    }
    int data = deque->rear->data;
    DequeNode *temp = deque->rear;
    deque->rear = deque->rear->prev;
    if (deque->rear)
        deque->rear->next = NULL;
    else
        deque->front = NULL;
    free(temp);
    deque->size--;
    return data;
}
// 销毁双端队列
void destroyDeque(Deque *deque) {
    if (!deque)
        return;
    while (!isEmpty(deque))
        deleteFront(deque);
    free(deque);
}
// 队列是否为空
bool isEmpty(Deque *deque) { return deque->size == 0 || deque == NULL; }
// 打印队列
//@param queue 队列指针
void printDeque(Deque *deque) {
    if (!deque) {
        printf("Queue is NULL!\n");
        return;
    }
    printf("Queue (size = %d): [", deque->size);
    DequeNode *current = deque->front;
    while (current) {
        printf("%d", current->data);
        if (current->next)
            printf("->");
        current = current->next;
    }
    printf("]\n");
}
/*--------测试--------*/
int main() {
    Deque *deque = createDeque();

    // 插入元素
    insertFront(deque, 10);
    insertRear(deque, 20);
    insertFront(deque, 30);
    insertRear(deque, 40);

    // 打印双端队列
    printf("双端队列的元素: ");
    printDeque(deque);

    // 删除元素
    printf("删除前端元素: %d\n", deleteFront(deque));
    printf("删除后端元素: %d\n", deleteRear(deque));

    // 打印双端队列
    printf("删除后的双端队列: ");
    printDeque(deque);

    // 销毁双端队列
    destroyDeque(deque);

    return 0;
}