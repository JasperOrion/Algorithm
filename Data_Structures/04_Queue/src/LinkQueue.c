//*队列的链式存储结构 因为链表删除简单时间复杂度O(1),不用像数组那样搞成循环
#include <stdio.h>
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int status;
typedef int QElemType;
//*节点结构
typedef struct
{
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;
//*队列的链表结构
typedef struct
{
    QueuePtr front, rear;
} LinkQueue;
//*入队操作,链表的尾插法
status EnQueue(LinkQueue *Q, QElemType e)
{
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    if (!s)
        exit(OVERFLOW);
    s->data = e;
    s->next = NULL;
    Q->rear->next = s;
    return OK;
}
//*出队操作，若队空返回ERROR，否则出队，并将队首元素值返回
status DeQueue(LinkQueue *Q, QElemType *e)
{
    if (Q->front == Q->rear)
        return ERROR;
    *e = Q->front->data;
    QueuePtr p = Q->front->next;
    Q->front->next = p->next;
    if (Q->rear == p)
        Q->rear = Q->front;
    free(p);
    return OK;
}
