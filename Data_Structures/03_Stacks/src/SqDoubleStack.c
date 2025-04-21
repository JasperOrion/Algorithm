//*两栈共享空间(双端栈)，一个数组，从两个方向压栈，出栈,top1+1==top2时，栈满
//*顺序栈，两栈共享空间，最大化利用数组空间
#include <stdio.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
// 定义元素类型
typedef int SElemType;
typedef int status;
typedef struct SqDoubleStack
{
    SElemType data[MAXSIZE];
    int top1, top2;
} SqDoubleStack;
// Push压栈,插入e作为新的栈顶元素，还需要stackNumber参数判断是几号栈
status Push(SqDoubleStack *S, SElemType e, int stackNumber)
{
    // 栈已满，ERROR
    if (S->top1 + 1 == S->top2)
        return ERROR;
    // 1号栈
    if (stackNumber == 1)
        S->data[++S->top1] = e; //*++S先加后用
    // {
    //     S->top1++;
    //     S->data[S->top1] = e;
    //     return OK;
    // }
    // 2号栈
    else if (stackNumber == 2)
        S->data[--S->top2] = e;
    // {
    //     S->top2--;
    //     S->data[S->top2] = e;
    //     return OK;
    // }
    return OK;
}
// Pop出栈,用*e来返回出栈元素，还需要stackNumber参数判断是几号栈
status Pop(SqDoubleStack *S, SElemType *e, int stackNumber)
{
    if (S->top1 == -1 || S->top2 == MAXSIZE)
        return ERROR;
    if (stackNumber == 1)
        *e = S->data[S->top1--];
    else if (stackNumber == 2)
        *e = S->data[S->top2++];
    return OK;
}
