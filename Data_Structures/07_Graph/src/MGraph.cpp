#include <iostream>
#include <queue>
using namespace std;

typedef char VertexType; //*顶点类型
typedef int EdgeType;    //*边的权值
#define MAXVEX 100       //*最大顶点数
#define INFINITY 65535   //*用65535表示∞

//*定义图的邻接矩阵储存的结构
typedef struct
{
    VertexType vexs[MAXVEX];      // 顶点表
    EdgeType arc[MAXVEX][MAXVEX]; // 邻接矩阵
    int numNodes, numEdges;       // 顶点和边的数量
} MGraph;

//*建立无向网图的邻接矩阵表示
void CreateMGraph(MGraph *G)
{
    int i, j, k, w;
    cout << "输入顶点数和边数: " << endl;
    cin >> G->numNodes >> G->numEdges;
    // 读入顶点信息,建立顶点表
    cout << "请输入顶点" << endl;
    for (i = 0; i < G->numNodes; i++)
        cin >> G->vexs[i];
    // 初始化邻接矩阵
    for (i = 0; i < G->numNodes; i++)
    {
        for (j = 0; j < G->numNodes; j++)
            G->arc[i][j] = INFINITY; // 默认值为65535作为 ∞//不带权时默认初始化为0
        G->arc[i][i] = 0;
    }

    // 读入numEdges条边
    for (k = 0; k < G->numEdges; k++)
    {
        cout << "请输入边(vi,vj)的下标i,j;还有对应的权值" << endl;
        cin >> i >> j >> w;
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j]; // 如果是有向矩阵注释掉这个
    }
}
bool visited[MAXVEX] = {false};

//*邻接矩阵的深度优先遍历算法
void DFS(MGraph G, int i)
{
    visited[i] = true;
    cout << G.vexs[i] << " ";
    for (int j = 0; j < G.numNodes; j++)
    {
        if (G.arc[i][j] == 1 && !visited[i])
            DFS(G, j);
    }
}
//*邻接矩阵的深度遍历操作
void DFSTraverse(MGraph G)
{
    for (int i = 0; i < G.numNodes; i++)
    {
        if (!visited[i])
            DFS(G, i); //*对未访问过的顶点调用DFS,若为连通图,只会执行一次
    }
}

int main()
{
    MGraph G;
    CreateMGraph(&G);
    cout << "图的顶点为: " << endl;
    for (int i = 0; i < G.numNodes; i++)
        cout << G.vexs[i] << " ";
    cout << endl;
    cout << "图的邻接矩阵为:" << endl;
    for (int i = 0; i < G.numNodes; i++)
    {
        for (int j = 0; j < G.numNodes; j++)
        {
            cout << G.arc[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
