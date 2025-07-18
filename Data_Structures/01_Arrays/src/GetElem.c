#include <stdio.h>
#define MAXSIZE 100

typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
} SeList;

//*初始化顺序表
void initList(SeList *list)
{
    list->length = 0;
}
//*添加元素-在尾部添加元素
int appendElem(SeList *list, ElemType data)
{
    if (!list)
    {
        printf("传入顺序表指针为 NULL");
        return 0;
    }
    if (list->length == MAXSIZE)
    {
        printf("顺序表已满\n无法添加");
        return 0;
    }
    list->data[list->length] = data;
    list->length++;
    return 1;
}
//*遍历顺序表并打印顺序表内容
void listElem(SeList *list)
{
    for (int i = 0; i < list->length; i++)
    {
        printf("%-5d", i);
    }
    printf("\n");
    for (int i = 0; i < list->length; i++)
    {
        printf("%-5d", list->data[i]);
    }
    printf("\n");
}
//*指定位置插入元素
int insertElem(SeList *list, int pos, ElemType data)
{
    if (!list || list->length == MAXSIZE)
    {
        printf("传入顺序表指针为 NULL或顺序表已满\n");
        return 0;
    }
    if (pos < 0 || pos > list->length)
    {
        printf("插入位置不当");
        return 0;
    }
    if (pos = list->length)
    {
        list->data[pos] = data;
        list->length++;
        return 1;
    }
    // pos及以后的位置往后平移一个
    for (int i = list->length - 1; i >= pos - 1; i--)
    {
        list->data[i + 1] = list->data[i];
    }
    list->data[pos] = data;
    list->length++;
    return 1;
}
//*指定位置删除元素
int deleteElem(SeList *list, int pos, ElemType *data)
{
    if (!list || list->length == 0)
    {
        printf("传入顺序表指针为 NULL或顺序表中无元素");
        return 0;
    }
    if (pos < 0 || pos >= list->length)
    {
        printf("删除位置不当");
        return 0;
    }
    *data = list->data[pos];

    if (list->length - 1 == pos)
    {
        list->length--;
        return 1;
    }
    for (int i = pos + 1; i < list->length; i++)
    {
        list->data[i - 1] = list->data[i];
    }
    list->length--;
    return 1;
}
//*查找线性表中第一个出现的元素data的下标
int findElem(SeList *list, ElemType data)
{
    if (!list)
        return -1;
    for (int i = 0; i < list->length; i++)
    {
        if (list->data == data)
            return i;
    }
    return -1;
}
/*----------测试代码----------*/
int main()
{
    SeList list;
    initList(&list);
    printf("初始化成功,目前长度占用%d\n", list.length);
    printf("目前占用内存%zu字节\n", sizeof(list.data));
    appendElem(&list, 88);
    appendElem(&list, 11);
    appendElem(&list, 22);
    appendElem(&list, 33);

    listElem(&list);
    printf("插入元素后\n");
    if (insertElem(&list, 4, 90))
        listElem(&list);
    int data = 0;
    if (deleteElem(&list, 4, &data))
    {
        printf("删除的值是%d\n", data);
        listElem(&list);
    }
    return 0;
}