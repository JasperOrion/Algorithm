//*二叉树的顺序结构存储
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define EMPTY -2345      // 表示空结点的值
#define INIT_CAPACITY 10 // 初始数组容量
int left_child_index(int index);
int right_child_index(int index);
typedef struct {
    int *tree;
    int size;
    int capacity;
} ArrayBinaryTree;

// 初始化二叉树
ArrayBinaryTree *creat_tree() {
    ArrayBinaryTree *abt = (ArrayBinaryTree *)malloc(sizeof(ArrayBinaryTree));
    abt->capacity = INIT_CAPACITY;
    abt->tree = (int *)malloc(abt->capacity * sizeof(int));
    abt->size = 0;
    // 初始化数组
    for (int i = 0; i < abt->capacity; i++)
        abt->tree[i] = EMPTY;
    return abt;
}
// 扩容数组
void resize(ArrayBinaryTree *abt, int new_capacity) {
    int *new_tree = (int *)malloc(new_capacity * sizeof(int));
    for (int i = 0; i < new_capacity; i++) {
        if (i < abt->capacity)
            new_tree[i] = abt->tree[i];
        else
            new_tree[i] = EMPTY;
    }
    free(abt->tree);
    abt->tree = new_tree;
    abt->capacity = new_capacity;
}
// 指定位置插入结点
void insert_at_index(ArrayBinaryTree *abt, int index, int value) {
    if (index < 0)
        return;
    if (index >= abt->capacity) {
        int new_capacity = 2 * abt->capacity;
        while (index >= new_capacity) {
            new_capacity *= 2;
        }
        resize(abt, new_capacity);
    }
    if (abt->tree[index] == EMPTY && value != EMPTY)
        abt->size++;
    else if (abt->tree[index] != EMPTY && value == EMPTY)
        abt->size--;
    abt->tree[index] = value;
}
// 在下一个可用位置插入结点
void insert(ArrayBinaryTree *abt, int value) {
    int i = 0;
    while (i < abt->capacity && abt->tree[i] != EMPTY)
        i++;
    if (i == abt->capacity)
        resize(abt, 2 * abt->capacity);
    abt->tree[i] = value;
    if (value != EMPTY)
        abt->size++;
}
// 删除指定索引结点
void delete_at_index(ArrayBinaryTree *abt, int index) {
    if (index < 0 && index >= abt->capacity)
        return;
    if (abt->tree[index] != EMPTY) {
        abt->tree[index] = EMPTY;
        abt->size--;
    }
}
// 获取父节点索引
int parent_index(ArrayBinaryTree *abt, int index) {
    if (index == 0)
        return -1;
    return (index - 1) / 2;
}
// 获取左子节点索引
int left_child_index(int index) { return 2 * index + 1; }
// 获取右子点索引
int right_child_index(int index) { return 2 * index + 2; }
// 层序遍历
void level_order_traversal(ArrayBinaryTree *abt) {
    printf("层序遍历: ");
    for (int i = 0; i < abt->capacity; i++) {
        if (abt->tree[i] != EMPTY)
            printf("%d->%d ", i, abt->tree[i]);
    }
    printf("\n");
}
//--------------------------------------------------------------
// 前序遍历辅助函数
void preorder_helper(ArrayBinaryTree *abt, int index) {
    if (index >= abt->capacity || abt->tree[index] == EMPTY)
        return;

    printf("%d ", abt->tree[index]);                // 访问根节点
    preorder_helper(abt, left_child_index(index));  // 遍历左子树
    preorder_helper(abt, right_child_index(index)); // 遍历右子树
}

// 前序遍历
void preorder_traversal(ArrayBinaryTree *abt) {
    printf("Preorder: ");
    preorder_helper(abt, 0);
    printf("\n");
}
//--------------------------------------------------------------
// 销毁二叉树，释放其内存
void free_tree(ArrayBinaryTree *abt) {
    free(abt->tree);
    free(abt);
}
// 测试
void test() {
    ArrayBinaryTree *abt = creat_tree();
    insert_at_index(abt, 0, 0);
    insert_at_index(abt, 1, 1);
    insert_at_index(abt, 2, 2);
    insert_at_index(abt, 4, 4);
    insert_at_index(abt, 6, 6);
    insert_at_index(abt, 9, 9);
    insert_at_index(abt, 10, 10);
    // 遍历二叉树
    level_order_traversal(abt);
    preorder_traversal(abt);
    //
    delete_at_index(abt, 6);
    printf("\nAfter deleting 6:\n");
    level_order_traversal(abt);
    preorder_traversal(abt);

    // 插入新节点
    insert(abt, 5);
    printf("\nAfter inserting 5:\n");

    level_order_traversal(abt);
    preorder_traversal(abt);
    // 释放内存
    free_tree(abt);
}
int main() {

    test();
    return 0;
}