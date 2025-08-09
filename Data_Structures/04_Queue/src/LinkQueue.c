/*基于链表实现的队列*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
/* --------------链表的结构定义 -----------*/
// 链表节点
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
// 队列结构
typedef struct
{
    Node *front;
    Node *rear;
    int size;
} LinkedListQueue;
/*---------------链表的结构操作------------*/
// 创建新节点
//@param data 节点数据
//@return 新节点指针
Node *create_node(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node)
    {
        perror("Memory allocation failed for new node");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
// 初始化队列
//@return 初始化后的队列指针
LinkedListQueue *queue_create()
{
    LinkedListQueue *queue = (LinkedListQueue *)malloc(sizeof(LinkedListQueue));
    if (!queue)
    {
        perror("Memory allocation failed for new node");
        return NULL;
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}
// 检查队列是否为空
//@param queue 队列指针
//@return true 队列为空,false 队列不为空
bool queue_is_empty(LinkedListQueue *queue)
{
    return queue->size == 0 || queue == NULL;
}
// 获取队列大小
//@param queue 队列指针
//@return 队列中元素的数量
int queue_size(LinkedListQueue *queue)
{
    return queue ? queue->size : 0;
}
// 入队操作
//@param queue 队列指针,data 要添加的数据
//@return true 入队成功,false 入队失败
bool enqueue(LinkedListQueue *queue, int data)
{
    if (!queue)
    {
        printf("Error: Queue is NULL\n");
        return false;
    }
    Node *new_node = create_node(data);
    if (!new_node)
        return false;
    if (queue_is_empty(queue))
    {
        // 此时队列为空，新节点是队首也是队尾
        queue->front = new_node;
        queue->rear = new_node;
    }
    else
    {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    queue->size++;
    return true;
}
// 出队操作
//@param queue 队列指针
//@return 移除元素的值
int dequeue(LinkedListQueue *queue)
{
    if (!queue)
    {
        printf("Error: Attempt to dequeue from an empty queue\n");
        // 这里的返回有些问题，但问题不大
        return 0;
    }
    Node *temp = queue->front;
    int data = queue->front->data;
    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;
    free(temp);
    queue->size--;
    return data;
}
// 查看队首元素
//@param queue 队列指针
//@return 队列首元素
int queue_peek(LinkedListQueue *queue)
{
    if (queue_is_empty(queue))
    {
        printf("Error: Attempt to peek from an empty queue\n");
        // 这样的返回并不完美
        return 0;
    }
    return queue->front->data;
}
// 清空队列
//@param queue 队列指针
void queue_clear(LinkedListQueue *queue)
{
    if (!queue)
        return;
    while (!queue_is_empty(queue))
        dequeue(queue);
}
// 销毁队列
//@param queue 队列指针
void queue_destroy(LinkedListQueue *queue)
{
    if (!queue)
        return;
    queue_clear(queue);
    free(queue);
}
// 打印队列
//@param queue 队列指针
void queue_print(LinkedListQueue *queue)
{
    if (!queue)
    {
        printf("Queue is NULL!\n");
        return;
    }
    printf("Queue (size = %d): [", queue->size);
    Node *current = queue->front;
    while (current)
    {
        printf("%d", current->data);
        if (current->next)
            printf("->");
        current = current->next;
    }
    printf("]\n");
}

// ======================= 示例用法 =======================

int main()
{

    // 创建并使用队列
    printf("\n===== Queue Usage Example =====\n");
    LinkedListQueue *queue = queue_create();

    printf("Enqueuing: 10, 20, 30\n");
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    queue_print(queue);

    printf("Peek: %d\n", queue_peek(queue));

    printf("Dequeuing: %d\n", dequeue(queue));
    queue_print(queue);

    printf("Enqueuing: 40, 50\n");
    enqueue(queue, 40);
    enqueue(queue, 50);
    queue_print(queue);

    printf("Dequeuing all elements:\n");
    while (!queue_is_empty(queue))
    {
        printf("Dequeued: %d\n", dequeue(queue));
    }
    queue_print(queue);

    queue_destroy(queue);

    return 0;
}