#include <stdio.h>
#include <stdlib.h>
typedef struct BiNode {
    char data;
    struct BiNode *left, *right;
    int ltag;
    int rtag;
} BiNode, *ThreadTree;

char str[] = "ABDH##I##EJ###CF##G##";
ThreadTree prev = NULL;
int idx = 0;

void createBiTree(ThreadTree *);
void inorderThreading(ThreadTree *, ThreadTree);
void threading(ThreadTree);
void InOrderTraversal(ThreadTree);
void NiInOrderTraversal(ThreadTree);

// 创建树
void createBiTree(ThreadTree *T) {
    char ch = str[idx++];
    if (ch == '#') {
        *T = NULL;
    } else {
        *T = (ThreadTree)malloc(sizeof(BiNode));
        (*T)->data = ch;
        createBiTree(&((*T)->left));
        if ((*T)->left != NULL)
            (*T)->ltag = 0;
        createBiTree(&((*T)->right));
        if ((*T)->right != NULL)
            (*T)->rtag = 0;
    }
}
// 具体线索化
void threading(ThreadTree curT) {
    if (curT != NULL) {
        threading(curT->left);

        if (curT->left == NULL) {
            curT->ltag = 1;
            curT->left = prev;
        }
        if (prev != NULL && prev->right == NULL) {
            prev->rtag = 1;
            prev->right = curT;
        }
        // 更新prev
        prev = curT;
        threading(curT->right);
    }
}
// 开始线索化
void inorderThreading(ThreadTree *head, ThreadTree T) {
    // 搞一个头结点
    *head = (ThreadTree)malloc(sizeof(BiNode));
    (*head)->ltag = 0;
    (*head)->rtag = 1;
    (*head)->left = T;
    (*head)->right = *head; // 现在还不知道中序遍历的最后一个节点
    prev = *head;
    threading(T);
    // 最后一个结点
    prev->right = *head;
    prev->rtag = 1;
    (*head)->right = prev;
}
// 使用线索进行中序遍历
void InOrderTraversal(ThreadTree head) {
    ThreadTree curr;
    curr = head->left;
    while (curr != head) {
        // 找到最左边的结点
        while (curr->ltag == 0)
            curr = curr->left;
        printf("%c ", curr->data);
        // 用线索遍历后继结点,
        while (curr->rtag == 1 && curr->right != head) {
            curr = curr->right;
            printf("%c ", curr->data);
        }
        // 转向右子树
        curr = curr->right;
    }
    printf("\n");
}
// 使用线索进行倒着中序遍历
void NiInOrderTraversal(ThreadTree head) {
    ThreadTree curr;
    curr = head->right;
    while (curr != head) {
        // 找到最右边的结点
        while (curr->rtag == 0)
            curr = curr->right;
        printf("%c ", curr->data);
        // 用线索遍历前继结点,
        while (curr->ltag == 1 && curr->left != head) {
            curr = curr->left;
            printf("%c ", curr->data);
        }
        // 转向左子树
        curr = curr->left;
    }
    printf("\n");
}
int main() {
    ThreadTree head;
    ThreadTree T;
    createBiTree(&T);
    inorderThreading(&head, T);
    InOrderTraversal(head);
    NiInOrderTraversal(head);
    return 0;
}
