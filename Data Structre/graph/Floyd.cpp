/*  
有权图的多源最短路径问题
*/

#include <iostream>
#include <queue>
using namespace std;

#define MaxVertexNum 10
#define infinity 1e9
struct Graph
{
    int edgenum;
    int vertexnum;
    int edgeList[MaxVertexNum][MaxVertexNum];
    int path[MaxVertexNum][MaxVertexNum]; // 前驱结点
    int dist[MaxVertexNum][MaxVertexNum]; // 从源点到其他各顶点当前最短路径长度
};

void BuildGraph(Graph *G)
{
    int start, end;
    cout << "Please enter the number of vertices and edges" << endl;
    cin >> G->vertexnum >> G->edgenum;
    // 图的权重初始化
    for (int i = 1; i <= G->vertexnum; i++)
    {
        for (int j = 1; j <= G->vertexnum; j++)
        {
            if (i == j)
            {
                G->edgeList[i][j] = 0;
            }
            else
            {
                G->edgeList[i][j] = infinity;
            }
            G->dist[i][j] = G->edgeList[i][j];
            G->path[i][j] = -1;
        }
    }
    // 输入权重信息
    for (int i = 1; i <= G->edgenum; i++)
    {
        cout << "Please enter the Start number, end number, weight" << endl;
        cin >> start >> end;
        cin >> G->edgeList[start][end];
        G->dist[start][end] = G->edgeList[start][end];
    }
}

void Floyd(Graph *G)
{
    for (int k = 1; k <= G->vertexnum; k++)
    {
        for (int i = 1; i <= G->vertexnum; i++)
        {
            for (int j = 1; j <= G->vertexnum; j++)
            {
                if (G->dist[i][k] + G->dist[k][j] < G->dist[i][j])
                {
                    G->dist[i][j] = G->dist[i][k] + G->dist[k][j];
                    G->path[i][j] = k;
                }
            }
        }
    }
}

int main()
{
    Graph G;
    BuildGraph(&G);
    Floyd(&G);
    cout << "edge" << endl;
    for (int i = 1; i <= G.vertexnum; i++)
    {
        for (int j = 1; j <= G.vertexnum; j++)
        {
            if (G.edgeList[i][j] != infinity)
            {
                printf("%10d", G.edgeList[i][j]);
            }
            else
            {
                printf("%10s", "infinity");
            }
        }
        cout << endl;
    }
    cout << "distance" << endl;
    for (int i = 1; i <= G.vertexnum; i++)
    {
        for (int j = 1; j <= G.vertexnum; j++)
        {
            cout << G.dist[i][j] << " ";
        }
        cout << endl;
    }
    cout << "path" << endl;
    for (int i = 1; i <= G.vertexnum; i++)
    {
        for (int j = 1; j <= G.vertexnum; j++)
        {
            cout << G.path[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}

/*  
4 8
1 4 4
4 1 5
4 3 12
3 4 1
1 3 6
3 1 7
1 2 2
2 3 3
*/