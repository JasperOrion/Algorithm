#include <stdio.h>
#define OK 1
#define ERROR 0

// 定义元素类型
typedef int ElemType;
typedef int status;
typedef struct DulNode
{
    ElemType data;
    struct DulNode *prior;
    struct DulNode *next;
} DulNode, *DulList;
