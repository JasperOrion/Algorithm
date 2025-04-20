#include <stdio.h>
#define MAXSIZE 1000
#define OK 1;
#define ERROR 0
// 定义元素类型
typedef int ElemType;
typedef int status;
typedef struct
{
    ElemType data;
    int cur; // 游标cursor,为零时表示无指向
} Component, StaticLinkList[MAXSIZE];
// 将数组连成一个链表,space[0].cur是头指针,"0"代表空指针
// 数组第一个元素cur用来存放备用链表(空闲空间)第一个节点的下标
// 最后一个元素cur用来存储第一个插入元素的下标,相当于头节点
status InitList(StaticLinkList space)
{
    for (int i = 0; i < MAXSIZE - 1; i++)
        space[i].cur = i + 1;
    space[MAXSIZE - 1].cur = 0;
    return OK;
}
// 静态链表的插入操作 数组无法操作malloc()和free(),需要借助空闲空间
// 如果备用链表非空，返回分配的节点下标，否则返回 0
int Malloc_SSL(StaticLinkList space)
{
    int i = space[0].cur;
    if (space[0].cur)
        space[0].cur = space[i].cur;
    return i;
}
// 静态链表的插入操作
status ListInsert(StaticLinkList L, int i, ElemType e)
{
    int j, k;
    k = MAXSIZE - 1;
    // 判断插入是否合规
    if (i < 1 || i > ListLength(L) + 1) // 注意插入的位置可以是ListLength(L)的位置，但删除不行
        return ERROR;
    j = Malloc_SSL(L);
    if (j)
    {
        for (int l = 1; i < i - 1; l++) // 找到第i个元素之前的位置，
            k = L[k].cur;
        L[j].data = e;
        // 千万不要颠倒
        L[j].cur = L[k].cur;
        L[k].cur = j;
        return OK;
    }
    return ERROR;
}
// 静态链表的删除操作
// Free_SSL()函数
void Free_SSL(StaticLinkList space, int k)
{
    space[k].cur = space[0].cur;
    space[0].cur = k;
}
// 删除L中第i个数据元素 e
status ListDelete(StaticLinkList L, int i)
{
    int j, k;
    k = MAXSIZE - 1;
    if (i < 1 || i > ListLength(L)) // 注意插入的位置可以是ListLength(L)的位置，但删除不行
        return ERROR;
    for (int l = 1; l < i - 1; l++)
        k = L[k].cur;
    j = L[k].cur; //
    L[k].cur = L[i].cur;
    Free_SSL(L, j);
    return OK;
}
int ListLength(StaticLinkList L)
{
    int length = 0;
    int i = L[MAXSIZE - 1].cur;
    while (i)
    {
        i = L[i].cur;
        length++;
    }
    return length;
}
