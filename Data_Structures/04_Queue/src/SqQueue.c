//*循环队列  使用数组实现 解决移动数据的损耗
/*  InitQueue(*Q    初始化队列
    DestroyQueue(*Q)若队列存在，销毁队列
    ClearQueue(*Q)清空
    QueueEmpty(Q) 判断是否为空
    Gethead(q,*e) 若队列存在且非空，返回队列首元素
    EnQueue(*Q,e)  入队  若队列存在，插入e到队尾
    DeQueue(*Q,*e) 出队  删除队首元素并返回其值
    QueueLength(Q) 返回队列长度
*/
#include <stdio.h>
#define MAXSIZE 20
#define OK 1
#define ERROR 0
typedef int status;
typedef int QElemType;
//*循环队列的顺序存储结构
typedef struct
{
    QElemType data[MAXSIZE];
    int front;
    int rear;
} SqQueue;
//* 初始化空队列
status InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return OK;
}
//*返回队列长度
int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}
//*若队列未满，入队
status EnQueue(SqQueue *Q, QElemType e)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front)
        return ERROR;
    Q->data[Q->front] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE; //%MAXSIZE，相当于一个循环
    return OK;
}
//*若队列非空，出队
status DeQueue(SqQueue *Q, QElemType *e)
{
    if (Q->front == Q->rear)
        return ERROR;
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return OK;
}
