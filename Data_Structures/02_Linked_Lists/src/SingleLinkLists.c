#include <stdio.h>
#define OK 1
#define ERROR 0

// 定义元素类型
typedef int ElemType;
typedef int status;
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;
// 定义LinkList
typedef struct Node *LinkList;
// 单链表读取获得第i个数据元素
// 初始条件:链式线性表已经存在,1<=i<=ListLength(l)
// 操作结果:用 e 返回L中第i个元素的值
status GetElem(LinkList L, int i, ElemType *e)
{
    LinkList p = L->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
    {
        return ERROR;
    }
    *e = p->data;
    return OK;
}
// 单链表的插入
// 初始条件:链式线性表已经存在,1<=i<=ListLength(l)
// 在L中第i个位置插入新的元素 e 链表长度加1
status LinkInsert(LinkList *L, int i, ElemType e)
{
    LinkList p, s;
    p = *L;
    int j = 1;
    // 寻找第i个节点
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }

    if (!p || j > i)
    {
        return ERROR;
    }
    s = (LinkList)malloc(sizeof(Node)); // 生成新节点
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}
// 单链表的删除
//  初始条件:链式线性表已经存在,1<=i<=ListLength(l)
// 在链表L中，删除第i个元素并用e返回它的值，L长度减1
status LinkDelete(LinkList *L, int i, ElemType *e)
{
    int j = 1;
    LinkList p, q;
    p = *L;

    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
    {
        return ERROR;
    }
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q); // 回收此节点，释放内存
    return OK;
}
// 随机产生n个元素的值，建立代表头结点的单链表 （头插法）
// 函数功能：使用头插法创建一个包含n个随机元素的单链表，L为指向头指针的指针
// 参数说明：
// - L：指向头指针的指针，通过修改*L来操作头指针，进而构建链表
// - n：要生成的链表节点数量
void CreateListHead(LinkList *L, int n)
{
    LinkList p;                          // 声明一个指针p，用于指向新创建的链表节点
    srand(time(0));                      // 利用当前时间（秒数）初始化随机数种子，保证每次运行生成不同随机序列
    *L = (LinkList)malloc(sizeof(Node)); // 为头结点分配内存空间，将头结点地址赋给*L
    (*L)->next = NULL;                   // 将头结点的next指针置为NULL，此时链表为空链表

    for (int i = 0; i < n; i++) // 循环n次，创建n个链表节点
    {
        p = (LinkList)malloc(sizeof(Node)); // 为新节点分配内存空间，p指向新节点
        p->data = rand() % 100 + 1;         // 生成1 - 100之间的随机数，赋值给新节点的数据域
        p->next = (*L)->next;               // 将新节点p的next指针指向头结点*L后的第一个节点（当前链表首元节点）
        (*L)->next = p;                     // 将头结点*L的next指针指向新节点p，完成头插操作
    }
}
// 随机产生n个元素的值，建立代表头结点的单链表 （尾插法）
void CreatListHead(LinkList *L, int n)
{
    LinkList p, r;
    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    r = *L; // r是指向尾部的节点
    for (int i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(Node));
        r->data = rand() % 100 + 1;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}
// 单链表的整表删除,个人理解就是从第一个开始删除,循环,直到指向NULL,最后将头节点指针设为空;
status ClearList(LinkList *L)
{
    LinkList p, q;
    p = (*L)->next;
    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;
}
//* 删除链表中绝对值相同的节点,再搞一个数组储存
// 拿空间换时间
void removeNode(Node *L, int n)
{
    Node *p = L;
    int index; // 做数组下标使用
    int *q = (int *)malloc(sizeof(int) * n + 1);
    for (int i = 0; i < n + 1; i++)
        *(q + i) = 0;
    while (p->next != NULL)
    {
        // abs获取绝对值
        index = abs(p->next->data);
        if (*(q + index) == 0)
        {
            *(q + index) = 1;
            p = p->next;
        }
        else
        {
            Node *temp = p->next;
            p->next = temp->next;
            free(temp);
        }
    }
    free(q);
}
//*反转链表
Node *reverseList(Node *head)
{
    Node *first = NULL;
    Node *second = head->next;
    Node *third;
    while (second != NULL)
    {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }
    Node *hd = initList();
    hd->next = first;
}
//*删除链表的中间节点
int DelMiddleNode(Node *head)
{
    if (head == NULL)
        return 0;
    Node *fast = head->next;
    Node *slow = head;
    while (fast != NULL || fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *temp = slow->next;
    slow->next = temp->next;
    free(temp);
    return 1;
}
//*重排链表顺序例如1 2 3  4 5 6 -->1 6 2  5 3 4
void reOrderList(Node *head)
{
    // 先找中间节点
    Node *fast = head->next;
    Node *slow = head;
    while (fast != NULL || fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *first = NULL;
    Node *second = slow->next;
    slow->next = NULL;
    Node *third;
    while (second != NULL)
    {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }
    Node *p1 = head->next;
    Node *q1 = first;
    Node *p2, *q2;
    while (p1 != NULL && q1 != NULL)
    {
        p2 = p1->next;
        q2 = q1->next;

        p1->next = q1;
        q1->next = p2;

        p1 = p2;
        q1 = q2;
    }
}
//*判断链表有无环
int isCycle(Node *head)
{
    Node *fast = head->next;
    Node *slow = head;
    while (fast != NULL && slow != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return 1;
    }
    return 0;
}
//*找到链表环的入口
Node *findBegin(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *fast = head->next;
    Node *slow = head;
    int count = 1;
    while (fast != NULL && slow != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {

            while (slow->next != fast)
            {
                count++;
                slow = slow->next;
            }
            fast = head;
            slow = head;
            for (int i = 0; i < count; i++)
            {
                fast = fast->next;
            }
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
    }
    return NULL;
}
