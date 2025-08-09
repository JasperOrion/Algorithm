/*基于环形数组实现的队列*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
typedef struct
{
    int *nums;       // 用于存储数组队列元素的的数组
    int front;       // 队首指针
    int queSize;     // 当前元素数量
    int queCapacity; // 队列容量
} ArrayQueue;
/*初始化队列*/
ArrayQueue *newArrayQueue(int capacity)
{
    ArrayQueue *queue = (ArrayQueue *)malloc(sizeof(ArrayQueue));
    queue->nums = (int *)malloc(sizeof(int) * capacity);
    queue->front = 0;
    queue->queSize = 0;
    queue->queCapacity = capacity;
    return queue;
}
/*清除队列*/
void delArrayQueue(ArrayQueue *queue)
{
    free(queue->nums);
    free(queue);
}
/*获取队列容量*/
int capacity(ArrayQueue *queue)
{
    return queue->queCapacity;
}
/*获取队列长度*/
int size(ArrayQueue *queue)
{
    return queue->queSize;
}
/*判断队列是否为空*/
bool empty(ArrayQueue *queue)
{
    return queue->queSize == 0;
}
/*访问队首元素*/
int peek(ArrayQueue *queue)
{
    assert(size(queue) != 0);

    return queue->nums[queue->front];
}
/*入队*/
void push(ArrayQueue *queue, int num)
{
    if (size(queue) == capacity(queue))
    {
        printf("队列已满\n");
        return;
    }
    // 通过计算,得到队列的尾部rear指向队列尾元素的下一个
    // 通过取余的操作实现循环
    int rear = (queue->front + queue->queSize) % queue->queCapacity;
    queue->nums[rear] = num;
    queue->queSize++;
}
/*出队*/
int pop(ArrayQueue *queue)
{
    assert(size(queue) != 0);
    int num = peek(queue);
    // 队首指针向后移动一位,若越过尾部,则返回到数组头部
    queue->front = (queue->front + 1) % queue->queCapacity;
    queue->queSize--;
    return num;
}
/*返回数组用于打印*/
int *toArray(ArrayQueue *queue, int *queSize)
{
    *queSize = queue->queSize;
    int *res = (int *)calloc(queue->queSize, sizeof(int));
    int j = queue->front;
    for (int i = 0; i < queue->queSize; i++, j++)
        res[i] = queue->nums[j % queue->queCapacity];
    return res;
}
// int main()
// {
//     ArrayQueue *queue = newArrayQueue(20);
// }
/*----------------------------------------------------*/
int main()
{
    // 1. 创建队列并测试初始化状态
    ArrayQueue *queue = newArrayQueue(5);
    printf("队列初始化后：\n");
    printf("容量：%d, 长度：%d, 空队列：%s\n",
           capacity(queue), size(queue),
           empty(queue) ? "是" : "否");

    // 2. 入队操作
    printf("\n--- 入队测试 ---\n");
    push(queue, 10);
    push(queue, 20);
    push(queue, 30);
    printf("入队 3 个元素后：\n");
    printf("队首元素：%d, 队列长度：%d\n", peek(queue), size(queue));

    // 3. 测试队列满的情况
    push(queue, 40);
    push(queue, 50);
    printf("入队 5 个元素后（队列已满）：\n");
    push(queue, 60); // 应提示"队列已满"

    // 4. 出队操作
    printf("\n--- 出队测试 ---\n");
    printf("出队元素：%d\n", pop(queue));
    printf("出队元素：%d\n", pop(queue));
    printf("剩余元素数量：%d\n", size(queue));

    // 5. 再次入队（测试环形特性）
    printf("\n--- 环形特性测试 ---\n");
    push(queue, 60);
    push(queue, 70);
    printf("再次入队 2 个元素后：\n");

    // 6. 打印队列内容
    printf("\n--- 队列内容 ---\n");
    int arrSize;
    int *arr = toArray(queue, &arrSize);
    printf("队列元素：");
    for (int i = 0; i < arrSize; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr); // 释放内存

    // 7. 清理资源
    delArrayQueue(queue);
    printf("\n测试完成！\n");
    return 0;
}