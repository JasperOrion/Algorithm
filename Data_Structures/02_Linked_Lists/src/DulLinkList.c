//*双向链表
#include <stdio.h>
#define OK 1
#define ERROR 0

// 定义元素类型
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *prev, *next;
} Node;
// 头插法
int insertHead(Node *L, ElemType e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    p->prev = L;
    p->next = L->next;
    if (L->next != NULL)
        L->next->prev = p;
    L->next = p;
    return 1;
}
// 尾插法
Node *insertTail(Node *tail, ElemType e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    p->prev = tail;
    tail->next = p;
    p->next = NULL;
    return p; // 返回尾节点
}
// 指定插
int insertNode(Node *L, int pos, ElemType e)
{
    Node *p = L;
    int i = 0;
    while (i < pos - 1)
    {
        p = p->next;
        i++;
        if (p == NULL)
        {
            return 0;
        }
    }
    Node *q = (Node *)malloc(sizeof(Node));
    q->data = e;

    q->prev = p;
    q->next = p->next;
    p->next->prev = q;
    p->next = q;
    return 1;
}