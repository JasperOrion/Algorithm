//*栈的顺序存储结构和实现
#include <stdio.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0

// 定义元素类型
typedef int SElemType;
typedef int status;
typedef struct
{
    SElemType data[MAXSIZE];
    int top;
} SqStack;
// push,压栈,插入e作为新的栈顶元素
status Push(SqStack *S, SElemType e)
{
    if (S->top == MAXSIZE - 1)
    {
        return ERROR;
    }
    S->top++;
    S->data[S->top] = e; // 将元素 e 存入栈顶指针指向的位置
    return OK;
}
// 若栈不为空，删除栈顶元素，并用*e返回其值，若为空，返回ERROR
status Pop(SqStack *S, SElemType *e)
{
    if (S->top == -1)
        return ERROR;
    *e = S->data[S->top];
    S->top--;
    return OK;
}
