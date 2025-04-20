//*栈的链式存储结构--链栈
#include <stdio.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
// 定义元素类型
typedef int SElemType;
typedef int status;

/*链栈的结构*/
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
} StackNode, *LinkStackPtr; // 为结构体类型和结构体指针类型分别起别名，方便后续使用
// 栈顶
typedef struct
{
    LinkStackPtr top; // 栈顶指针，指向链栈的栈顶节点
    int count;        // 记录链栈中元素的个数
} LinkStack;
// 压栈操作,插入e
status Push(LinkStack *S, SElemType e)
{
    // LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    StackNode *s = (StackNode *)malloc(sizeof(StackNode));
    s->data = e;
    s->next = S->top;
    S->top = s;
    S->count++;
    return OK;
}
// 出栈，如果栈不为空，出栈e返回OK，否则返回ERROR
status Pop(LinkStack *S, SElemType *e)
{
    if (StackEmpty(S))
        return ERROR;
    LinkStackPtr p;
    *e = S->top->data;
    p = S->top;
    S->top = p->next;
    free(p);
    S->count--;
    return OK;
}
status StackEmpty(LinkStack *S)
{
    // 先检查传入的链栈指针是否为空
    if (S == NULL)
        return ERROR;
    // 如果栈顶指针为空，说明栈为空，返回成功标识
    if (!S->top)
        return OK;
    // 否则栈不为空，返回错误标识
    return ERROR;
}