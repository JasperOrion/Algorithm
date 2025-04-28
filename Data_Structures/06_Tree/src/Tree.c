#include <stdio.h>
#define MAX_TREE_SIZE 100
typedef int TElemType;

//*树的孩子表示法结构定义
typedef struct CTNode // 孩子节点
{
    int child;
    struct CTNode *next;
} *ChildPtr;

typedef struct
{ // 表头结构
    TElemType data;
    ChildPtr firstchild;

} CTBox;

typedef struct
{
    CTBox nodes[MAX_TREE_SIZE]; // 节点数组
    int r, n;                   // 根的位置和节点数值
} CTree;
//*树的孩子表示法，plus版  增加孩子对双亲节点的指针
typedef struct CTNode // 孩子节点不变
{
    int child;
    int parent;
    struct CTNode *next;
} *ChildPtr, *ParentPtr;

typedef struct
{ // 表头结构
    TElemType data;
    ChildPtr firstchild;
    ParentPtr parent;
} CTBox;

typedef struct
{
    CTBox nodes[MAX_TREE_SIZE]; // 节点数组
    int r, n;                   // 根的位置和节点数值
} CTree;

//*孩子兄弟表示法
typedef struct
{
    TElemType data;
    struct CSNode *firstchild, *right;
} CSNode, *CSTree;