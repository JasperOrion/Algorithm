#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 有头节点的单链表1
//  定义结点的结构
typedef struct ListNode
{
    int data;
    struct ListNode *next;
} ListNode;

// 定义链表的结构
typedef struct
{
    ListNode *head;
    int length;
} LinkedList;

/*=========链表的操作时实现==========*/

// 创建链表
LinkedList *createLinkedList()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    if (!list)
        return NULL;
    list->head = (ListNode *)malloc(sizeof(ListNode));
    if (!list->head)
    {
        free(list);
        return NULL;
    }
    list->length = 0;
    list->head->next = NULL;
    return list;
}

// 销毁链表
void destroyLinkedList(LinkedList *list)
{
    if (!list)
        return;

    //*从头结点开始释放
    ListNode *current = list->head;
    while (current)
    {
        ListNode *temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

// 判断链表是否为空
bool isEmpty(LinkedList *list)
{
    return list ? list->length == 0 : true;
}
// 获取链表长度
int getLength(LinkedList *list)
{
    return list ? list->length : 0;
}
// 打印链表
void printList(LinkedList *list)
{
    if (!list)
    {
        printf("List is NULL !\n");
        return;
    }
    printf("List(length=%d)", list->length);
    ListNode *current = list->head->next;
    while (current)
    {
        printf("%d", current->data);
        if (current->next)
        {
            printf("->");
        }
        current = current->next;
    }
    printf("\n");
}

//*头插法插入结点
bool insertAtHead(LinkedList *list, int data)
{
    if (!list)
        return false;
    // 分配新结点
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (!newNode)
        return false;
    newNode->data = data;
    newNode->next = list->head->next;
    list->head->next = newNode;
    list->length++;
    return true;
}
//*尾插法插入结点
bool insertAtTail(LinkedList *list, int data)
{
    if (!list)
        return false;
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (!newNode)
        return false;
    newNode->data = data;
    newNode->next = NULL;
    // 寻找最后一个结点
    ListNode *current = list->head;
    while (current->next)
    {
        current = current->next;
    }
    current->next = newNode;
    list->length++;
    return true;
}
//*任意位置插入结点
bool insertAtIndex(LinkedList *list, int index, int data)
{
    if (!list || index < 0 || index > list->length)
        return false;
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (!newNode)
        return false;
    newNode->data = data;
    // 寻找待插入位置的前一个结点
    ListNode *prev = list->head;
    for (int i = 0; i < index; i++)
        prev = prev->next;

    newNode->next = prev->next;
    prev->next = newNode;
    list->length++;

    return true;
}
// 删除首元节点
bool deleteAtHead(LinkedList *list)
{
    if (!list || list->length == 0)
        return false;
    ListNode *temp = list->head->next;
    list->head->next = temp->next;
    free(temp);
    list->length--;
    return true;
}
// 删除尾结点
bool deleteAtTail(LinkedList *list)
{
    if (!list || list->length == 0)
        return false;
    ListNode *prev = list->head;
    // ListNode *prev = list->head->next;遍历寻找结点时好用些，
    // 从头结点开始找，避免空指针异常
    while (prev->next && prev->next->next)
        prev = prev->next;
    free(prev->next);
    prev->next = NULL;
    list->length--;
    return true;
}
// 删除指定位置结点
bool deleteAtIndex(LinkedList *list, int index)
{
    if (!list || index >= list->length || index < 0)
        return false;
    ListNode *prev = list->head;
    for (int i = 0; i < index; i++)
    {
        prev = prev->next;
    }
    ListNode *temp = prev->next;
    prev->next = temp->next;
    free(temp);
    list->length--;
    return true;
}
// 查找数据的位置,返回链表结点的下标
int find(LinkedList *list, int data)
{
    if (!list || list->length == 0 || !list->head)
        return -1;
    ListNode *current = list->head->next;
    int index = 0;
    while (current)
    {
        if (current->data == data)
            return index;
        current = current->next;
        index++;
    }
    return -1;
}
// 获取指定位置的数据
// 更新指定位置数据
int getAtIndex(LinkedList *list, int index)
{
    if (!list || !list->head || index >= list->length || index < 0)
    {
        printf("指定位置下表在链表中不存在或链表为空,返回值 -1 \n");
        return -1;
    }
    // 寻找下标为index的结点,
    // 从首元结点开始移动index-1步到下表为index的结点
    ListNode *current = list->head->next;
    for (int i = 0; i < index; i++)
        current = current->next;
    return current->data;
}
// 更新指定位置数据
bool updateAtIndex(LinkedList *list, int index, int data)
{
    if (!list || !list->head || index >= list->length || index < 0)
        return false;
    // 寻找下标为index的结点,
    // 从首元结点开始移动index-1步到下表为index的结点
    ListNode *current = list->head->next;
    for (int i = 0; i < index; i++)
        current = current->next;
    current->data = data;
    return true;
}
/******************** 测试代码 ********************/

int main()
{
    // 创建链表
    LinkedList *list = createLinkedList();
    if (!list)
    {
        printf("Failed to create list\n");
        return -1;
    }

    printf("New list created. Empty? %s\n", isEmpty(list) ? "Yes" : "No");

    // 插入测试
    insertAtHead(list, 10);
    insertAtHead(list, 20);
    insertAtTail(list, 30);
    insertAtIndex(list, 1, 15);
    printList(list); // 应该输出: 20 -> 15 -> 10 -> 30

    // 查找测试
    int index = find(list, 10);
    printf("Value 10 found at index: %d\n", index);

    // 获取测试
    printf("Value at index 2: %d\n", getAtIndex(list, 2));

    // 更新测试
    updateAtIndex(list, 1, 25);
    printList(list); // 应该输出: 20 -> 25 -> 10 -> 30

    // 删除测试
    deleteAtHead(list);
    deleteAtTail(list);
    deleteAtIndex(list, 1);
    printList(list); // 应该输出: 25 -> 10

    // 销毁链表
    destroyLinkedList(list);

    return 0;
}