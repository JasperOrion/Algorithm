#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_OP 20
typedef struct vector
{
    int size, count;
    int *data;
} vector;
//*顺序表初始化
vector *getNewVector(int len)
{
    vector *p = (vector *)malloc(sizeof(vector));
    p->size = len;
    p->count = 0;
    p->data = (int *)malloc(sizeof(int) * len);
    return p;
}

//*销毁顺序表
void clear(vector *v)
{
    if (v == NULL)
        return;
    free(v->data);
    free(v);
}
//*输出顺序表
void output_vector(vector *v)
{
    int len = 0;
    for (int i = 0; i < v->size; i++)
        len += printf("%3d", i);
    printf("\n");
    for (int i = 0; i < len; i++)
        printf("-");
    printf("\n");
    for (int i = 0; i < v->count; i++)
        printf("%3d", v->data[i]);
    printf("\n");
    printf("\n\n");

    return;
}
//*扩容
// int expend(vector *v)
// {
//     if (v == NULL)
//         return 0;
//     printf("expend v from %d to %d\n", v->size, 2 * v->size);
//     v->data = (int *)realloc(v->data, sizeof(int) * 2 * v->size);
//     v->size *= 2;
//     return 1;
// }

//*插入操作
int insert(vector *v, int pos, int val)
{
    if (v->size == v->count)
        return 0;
    // 边界检查：pos必须在[0, count]范围内
    if (pos < 0 || pos > v->count)
        return 0; // 插入位置无效

    for (int i = v->count - 1; i >= pos; i--)
    {
        v->data[i + 1] = v->data[i];
    }
    v->data[pos] = val;
    v->count++;
    return 1;
}

//*删除元素操作
int erase(vector *v, int pos)
{
    if (v == NULL || pos >= v->count || pos < 0)
        return 0;
    for (int i = pos + 1; i < v->count; i++)
    {
        v->data[i - 1] = v->data[i];
    }
    v->count--;
    return 1;
}

int main()
{
    srand(time(0));
    vector *v = getNewVector(MAX_OP);
    for (int i = 0; i < MAX_OP; i++)
    {
        int op = rand() % 4, pos, val, ret;
        switch (op)
        {
        case 0:
        case 1:
        case 2:
            pos = rand() % (v->count + 2);
            val = rand() % 100;
            ret = insert(v, pos, val);
            printf("insert %d at %d to vector = %d\n", val, pos, ret);
            break;
        case 3:
            pos = rand() % (v->count + 2);
            ret = erase(v, pos);
            printf("erase item at %d in vector = %d\n", pos, ret);
            break;
        }
        output_vector(v);
    }
    clear(v);
    return 0;
}