//*线索二叉树
#include <stdio.h>
typedef char TElemType;

typedef struct BiThrNode
{
    TElemType data;
    struct BiThrNode *lchild, *rchild;
    int LTag, RTag;
} BiThrNode, *BiThrTree;

//*中序遍历的
void InThread(BiThrTree p, BiThrTree *pre)
{
    if (p != NULL)
    {
        InThread(p->lchild, pre); // 递归，线索化左子树
        if (p->lchild == NULL)
        {                     // 左子树为空，建立前驱线索
            p->lchild = *pre; //*当递归到这个节点时，由于其左子树为空此时，*pre 指向的是头结点（因为 pre 初始化为头结点，且在处理第一个节点之前没有被更新），所以第一个节点的左指针 lchild 就指向了头结点
            p->LTag = 1;
        }
        if ((*pre) != NULL && (*pre)->rchild == NULL)
        {
            (*pre)->rchild = p; // 建立前驱结点的后继线索
            (*pre)->RTag = 1;
        }
        *pre = p;                 // 标记当前结点成为刚刚访问过的结点
        InThread(p->rchild, pre); // 递归，线索化右子树
    }
}
//*线索化树
void inOrderThreading(BiThrTree *head, BiThrTree T)
{
    *head = (BiThrTree)malloc(sizeof(BiThrTree)); // 头结点
    (*head)->LTag = 0;
    (*head)->RTag = 1;
    (*head)->rchild = *head; // 现在尾结点还不知道,准备遍历
    // 这里我先默认树不为空了
    (*head)->lchild = T;
    BiThrTree pre = (*head);

    InThread(T, &pre);

    // 最后结点的线索化
    pre->rchild = *head;
    pre->RTag = 1;
    // 头结点右孩子指向最后一个结点
    (*head)->rchild = pre;
}
//*使用线索进行遍历
void inOrder(BiThrTree T)
{
    BiThrTree curr;
    curr = T->lchild;
    while (curr != T) // 循环到头结点时,循环结束
    {
        while (curr->LTag == 0)
            curr = curr->lchild;
        printf("%c", curr->data);
        while (curr->RTag == 1 && curr->rchild != T)
        {
            curr = curr->rchild; // 依据线索访问下一个结点位置
            printf("%c", curr->data);
        }
        curr = curr->rchild;
    }
}