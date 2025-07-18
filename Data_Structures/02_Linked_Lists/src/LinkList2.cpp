#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 无头结点的链表
typedef struct Node
{
    int data;
    struct Node *next;
} Node, *Linklist;

// 创建节点
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("创建结点失败");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// 头插
bool insertAtHead(Linklist *head, int data)
{
    Node *newNode = createNode(data);
    if (!newNode)
        return false;
    //*将新结点的next指向现在头指针的位置
    //*再将新的头指针指向newNode
    newNode->next = *head;
    *head = newNode;
    return true;
}
// 尾插
bool insertAtTail(Linklist *head, int data)
{
    Node *newNode = createNode(data);
    if (!newNode)
        return false;
    if (!*head)
    {
        *head = newNode;
        return true;
    }

    Node *temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    return true;
}
// 指定位置插入
bool insertAtIndex(Linklist *head, int data, int index)
{
    if (index < 0)
    {
        printf("位置插入无效\n");
        return false;
    }
    if (index == 0)
    {
        printf("插入位置在头部\n");
        return insertAtHead(head, data);
    }
    // 接下来是寻找插入位置的前一位
    Node *newNode = createNode(data);
    Node *temp = *head;
    for (int i = 1; i < index; i++)
    {
        temp = temp->next;
        if (!temp)
        {
            printf("下标超出链表长度\n");
            free(newNode);
            return false;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return true;
}
// 删除第一个结点
bool deleteAtHead(Linklist *head)
{
    if (!*head)
        return false;
    Node *temp = *head;
    *head = temp->next;
    free(temp);
    return true;
}
// 删除最后一个节点
bool deleteAtTail(Linklist *head)
{
    if (!*head)
        return false;
    Node *prev = *head;
    if (!prev->next)
        return deleteAtHead(head);
    while (prev->next && prev->next->next)
        prev = prev->next;
    free(prev->next);
    prev->next = NULL;
    return true;
}
// 删除任意一个结点
bool deleteAtIndex(Linklist *head, int index)
{
    /*
    判断蓝标是否为空
    判断删除位置是否合规 <0 和超出链表长度的
    针对第一个结点做特殊处理
    寻找删除结点的前一个结点prev
    */
    if (!*head || index < 0)
        return false;
    if (index == 0)
        return deleteAtHead(head);
    Node *prev = *head;
    for (int i = 1; i < index; i++)
    {
        if (!prev->next)
            return false;
        prev = prev->next;
    }
    Node *temp = prev->next;
    prev->next = temp->next;
    free(temp);
    return true;
}
// 查找结点
int getAtIndex(Linklist *head, int index)
{
    if (!*head || index < 0)
    {
        printf("链表为空/或查找位置不当，返回-1\n");
        return -1;
    }
    Node *temp = *head;
    for (int i = 0; i < index; i++)
    {
        if (!temp->next)
            return -1;
        temp = temp->next;
    }
    return temp ? temp->data : -1;
}
// 查找节点位置（返回第一次出现的位置，从0开始计数）
int searchNode(Node *head, int data)
{
    Node *temp = head;
    int position = 0;

    while (temp != NULL)
    {
        if (temp->data == data)
        {
            return position;
        }
        temp = temp->next;
        position++;
    }

    return -1; // 未找到
}
void printList(Linklist head)
{
    if (!head)
    {
        printf("链表为空\n");
        return;
    }
    Node *temp = head;
    while (temp)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
// 获取链表长度
int getLength(Linklist head)
{
    int length = 0;
    Node *temp = head;
    while (temp) // 当temp不为NULL时继续计数
    {
        length++;
        temp = temp->next;
    }
    return length;
}
// 释放整个链表
void freeList(Linklist *head)
{
    Node *temp;
    while (*head)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// 主函数测试链表操作
int main()
{
    Node *head = NULL; // 初始化空链表

    printf("=== 单链表测试程序 ===\n");

    // 测试插入操作
    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtHead(&head, 5);
    insertAtIndex(&head, 15, 2);
    printList(head); // 输出: 5 -> 10 -> 15 -> 20

    // 测试删除操作
    deleteAtHead(&head);
    deleteAtTail(&head);
    printList(head); // 输出: 10 -> 15

    // 测试查找和长度
    printf("元素15的位置: %d\n", searchNode(head, 15)); // 输出: 1
    printf("链表长度: %d\n", getLength(head));          // 输出: 2

    // 测试边界情况
    deleteAtIndex(&head, 3); // 测试超出位置
    deleteAtIndex(&head, 1); // 删除尾节点
    printList(head);         // 输出: 10

    // 清理链表
    freeList(&head);

    return 0;
}