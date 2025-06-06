#include <iostream>
#include <queue>
using namespace std;

typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100 //*最大顶点数

//*边表结点结构
typedef struct EdgeNode
{
    int adjvex;            // 存储结点对应下标
    EdgeType weight;       // 权值
    struct EdgeNode *next; // 指向下一个邻接点
} EdgeNode;
//*顶点表结点
typedef struct VertexNode
{
    VertexType data;     // 顶点域,存储顶点信息
    EdgeNode *firstedge; // 边表 头指针
} VertexNode, AdjList[MAXVEX];
//*图的邻接表结构
typedef struct
{
    AdjList adjList;
    int numNode, numEdges; // 图中的顶点数和边数
} GraphAdjList;

//*无向图的邻接表结构
/*
无向图,对于每一条边,顶点都要链上一次
对于无向图的邻接表结构,每一个顶点的度为链的长度,边的长度为总度/2
*/
void CreateALGraph(GraphAdjList *G)
{
    int i, j, k, w;
    EdgeNode *e;
    cout << "输入顶点数和边数" << endl;
    cin >> G->numNode >> G->numEdges;
    // 输入顶点数据并初始化,置为空表
    for (i = 0; i < G->numNode; i++)
    {
        cin >> G->adjList[i].data;
        G->adjList[i].firstedge = NULL;
    }

    // 建立边表,注意这是无向图
    for (k = 0; k < G->numEdges; k++)
    {
        cout << "输入(vi,vj)上的顶点序号i,j和权值w:" << endl;
        cin >> i >> j >> w;
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = j; // 存储结点对应的下标
        e->weight = w;
        e->next = G->adjList[i].firstedge;
        G->adjList[k].firstedge = e;

        e->adjvex = i; // 存储结点对应的下标
        e->weight = w;
        e->next = G->adjList[j].firstedge;
        G->adjList[k].firstedge = e;
    }
}
bool visited[MAXVEX] = {false};
//*邻接矩阵的深度优先遍历算法
void DFS(GraphAdjList GL, int i)
{
    visited[i] = true;
    cout << GL.adjList[i].data << " ";
    EdgeNode *p = GL.adjList[i].firstedge;
    while (p)
    {
        if (!visited[p->adjvex])
            DFS(GL, p->adjvex);
        p = p->next;
    }
}
//*邻接矩阵的深度遍历操作
void DFSTraverse(GraphAdjList GL)
{
    for (int i = 0; i < GL.numNode; i++)
    {
        if (!visited[i])
            DFS(GL, i); //*对未访问过的顶点调用DFS,若为连通图,只会执行一次
    }
}
