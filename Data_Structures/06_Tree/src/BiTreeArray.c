//*二叉树的链式存储
#include <stdio.h>
typedef char ElemType;

typedef struct TreeNode
{
    ElemType data;
    TreeNode *lchild;
    TreeNode *rchild;
} TreeNode, *BiTree;