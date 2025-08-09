#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 100

typedef struct
{
    int data;
    int next;
} SNode;

typedef struct
{
    SNode list[MAXSIZE];
} StaticList;

//*初始化静态链表
void InitList(StaticList *Slist)
{
    // 静态链表固定头结点
    Slist->list[MAXSIZE - 1].next = -1;
    // 固定空闲链表头结点
    Slist->list[0].next = 1;
    for (int i = 0; i < MAXSIZE - 2; i++)
        Slist->list[i].next = i + 1;
    // 最后一个空闲节点
    Slist->list[MAXSIZE - 2].next = -1;
}
//*分配空闲节点,成功分配返回索引,否则返回-1
int Malloc(StaticList *Slist)
{
    int index = Slist->list[0].next;
    if (index == -1)
        return -1;
    // 跟新空闲链表表头
    Slist->list[0].next = Slist->list[index].next;
    return index;
}
//*释放结点到空链表
void Free(StaticList *Slist, int index)
{
    Slist->list[index].next = Slist->list[0].next;
    Slist->list[0].next = index;
}

// 在pos位置处插入结点
bool ListInsert(StaticList *Slist, int pos, int data)
{
    if (pos < 1)
        return false;
    int cur = MAXSIZE - 1;
    int count = 0;
    while (cur != -1 && count < pos - 1)
    {
        cur = Slist->list[cur].next;
        count++;
    }
    if (cur == -1 || count < pos - 1)
        return false;

    int newIndex = Malloc(Slist);
    if (newIndex == -1)
        return false;
    Slist->list[newIndex].data = data;
    Slist->list[newIndex].next = Slist->list[cur].next;
    Slist->list[cur].next = newIndex;

    return true;
}
// 删除pos位置处的元素
bool ListDelete(StaticList *Slist, int pos)
{
    if (pos < 1)
        return false;
    int prev = MAXSIZE - 1;
    int count = 0;
    while (prev != -1 && count < pos - 1)
    {
        prev = Slist->list[prev].next;
        count++;
    }
    if (prev == -1 || count < pos - 1)
        return false;
    int deleteindex = Slist->list[prev].next;
    if (deleteindex == -1)
        return false;
    Slist->list[prev].next = Slist->list[deleteindex].next;
    Free(Slist, deleteindex);
    return true;
}
// 遍历
void PrintList(StaticList *Slist)
{
    int current = Slist->list[MAXSIZE - 1].next;
    printf("StaticList [");
    while (current != -1)
    {
        printf("%d", Slist->list[current].data);
        current = Slist->list[current].next;
        if (current != -1)
            printf("->");
    }
    printf(" ]\n");
    // 打印空链表信息
    int freeCount = 0;
    int freeCur = Slist->list[0].next;
    while (freeCur != -1)
    {
        freeCount++;
        freeCur = Slist->list[freeCur].next;
    }
}
int main()
{
    StaticList L;
    InitList(&L);

    // 功能演示
    printf("Inserting elements...\n");
    ListInsert(&L, 1, 10); // 位置1插入10
    ListInsert(&L, 1, 20); // 位置1插入20(头插)
    ListInsert(&L, 3, 30); // 位置3插入30(尾插)
    PrintList(&L);         // 预期: 20 -> 10 -> 30

    printf("\nInserting at position 2...\n");
    ListInsert(&L, 2, 15); // 中间插入
    PrintList(&L);         // 预期: 20 -> 15 -> 10 -> 30

    printf("\nDeleting position 3...\n");
    ListDelete(&L, 3); // 删除元素
    PrintList(&L);     // 预期: 20 -> 15 -> 30

    printf("\nAttempting invalid operations...\n");
    if (!ListInsert(&L, 10, 100))
    {
        printf("Failed to insert at invalid position\n");
    }
    if (!ListDelete(&L, 5))
    {
        printf("Failed to delete at invalid position\n");
    }

    return 0;
}
