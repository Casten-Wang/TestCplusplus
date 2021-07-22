/*  
最小生成树 Prim算法
*/

#include <iostream>
using namespace std;

#define MaxVertexNum 10

struct Graph
{
    int edgenum;
    int vertexnum;
    int edgeList[MaxVertexNum][MaxVertexNum];
    int parent[MaxVertexNum]; // 树的父亲结点
    int dist[MaxVertexNum];   // 到树的距离
};

void BuildGraph(Graph *G)
{
    int start, end;
    cout << "Please enter the number of vertices and edges" << endl;
    cin >> G->vertexnum >> G->edgenum;
    // 图的权重初始化
    for (int i = 1; i <= G->vertexnum; i++)
    {
        G->parent[i] = -1;
        G->dist[i] = INT_MAX;
        for (int j = 1; j <= G->vertexnum; j++)
        {
            G->edgeList[i][j] = 0;
        }
    }
    // 输入权重信息
    for (int i = 1; i <= G->edgenum; i++)
    {
        cout << "Please enter the Start number, end number, weight" << endl;
        cin >> start >> end;
        cin >> G->edgeList[start][end];
        G->edgeList[end][start] = G->edgeList[start][end];
    }
    cout << endl;
}

void Prim(Graph *G)
{
    int firstvertex = 1;
    G->dist[firstvertex] = 0;
    for (int i = 1; i <= G->vertexnum; i++)
    {
        if (G->edgeList[firstvertex][i])
        {
            G->dist[i] = G->edgeList[firstvertex][i];
            G->parent[i] = firstvertex;
        }
    }
    while (true)
    {
        // 寻找不在树里的结点中离树的距离最短的
        int minvertex, mindist = INT_MAX;
        for (int i = 1; i <= G->vertexnum; i++)
        {
            if (G->dist[i] != 0 && G->dist[i] < mindist)
            {
                mindist = G->dist[i];
                minvertex = i;
            }
        }
        // 循环结束条件：都在树中
        if (mindist == INT_MAX)
        {
            break;
        }
        // 将找到的点放入树中
        G->dist[minvertex] = 0;
        cout << "-->" << minvertex;
        // 以minvertex为源点扩散更新dist
        for (int i = 1; i <= G->vertexnum; i++)
        {
            // 寻找源点的邻接点且不在树中
            if (G->dist[i] != 0 && G->edgeList[minvertex][i])
            {
                // 如果距离小于原来的dist，则更新
                if (G->edgeList[minvertex][i] < G->dist[i])
                {
                    G->dist[i] = G->edgeList[minvertex][i];
                    G->parent[i] = minvertex;
                }
            }
        }
    }
    cout << endl;
}

int main()
{
    Graph G;
    BuildGraph(&G);
    Prim(&G);
    cout << "distance" << endl;
    for (int i = 1; i <= G.vertexnum; i++)
    {
        cout << G.dist[i] << " ";
    }
    cout << endl;
    cout << "parent" << endl;
    for (int i = 1; i <= G.vertexnum; i++)
    {
        cout << G.parent[i] << " ";
    }
    system("pause");
    return 0;
}

/*  
6 10
1 2 6
1 4 5
1 3 1
2 3 5
3 4 5
3 5 6
3 6 4
5 6 6
2 5 3
4 6 2
*/