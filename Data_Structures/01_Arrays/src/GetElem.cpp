#include <iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define MAXSIZE 20
// 定义元素类型
typedef int ElemType;
typedef int status;
// 定义顺序结构体
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
} Sqlist;
// 获得数组元素操作
// 获取顺序表L中第i个元素，通过指针 e 来返回

status GetElem(Sqlist L, int i, ElemType *e)
{
    // Get the i-th element of the list L
    if (i < 1 || i > L.length || L.length == 0)
        return ERROR; // 位置i越界
    *e = L.data[i - 1];
    return OK;
}
// 插入操作
status ListInsert(Sqlist *L, int i, ElemType e)
{
    if (L->length == MAXSIZE)
    {
        return ERROR;
    }
    else if (i < 1 || i > L->length + 1)
    {
        return ERROR;
    }
    else
    {
        for (int k = L->length; k >= i - 1; k--)
        {
            L->data[k + 1] = L->data[k];
        }
    }
    L->data[i - 1] = e;
    L->length++;
    return OK;
}
// 删除操作
status ListDelete(Sqlist *L, int i, ElemType *e) // 为什么给的是*e
{
    if (L->length == 0)
    {
        return ERROR;
    }
    else if (i < 1 || i > L->length)
    {
        return ERROR;
    }
    else
    {
        for (int k = i; k < L->length; k++)
        {
            L->data[k - 1] = L->data[k];
        }
    }
    L->length--;
    return OK;
}
