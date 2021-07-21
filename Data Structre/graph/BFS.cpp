/* 
通过邻接矩阵实现BFS
*/

#include <iostream>
#include <queue>
using namespace std;

#define MaxVertexNum 10

struct Graph
{
    int vertexnum;
    int edgenum;
    bool visit[MaxVertexNum];
    int edgeList[MaxVertexNum][MaxVertexNum];
};

void BuildGraph(Graph *G)
{
    int start, end;
    cout << "Please enter the number of vertices and edges" << endl;
    cin >> G->vertexnum >> G->edgenum;
    // 图的权重初始化
    for (int i = 0; i < G->vertexnum; i++)
    {
        G->visit[i] = false;
        for (int j = 0; j < G->vertexnum; j++)
        {
            G->edgeList[i][j] = 0;
        }
    }
    // 输入权重信息
    for (int i = 0; i < G->edgenum; i++)
    {
        cout << "Please enter the Start number, end number, weight" << endl;
        cin >> start >> end;
        cin >> G->edgeList[start][end];
        G->edgeList[end][start] = G->edgeList[start][end];
    }
    cout << endl;
}

void BFS(Graph *G)
{
    queue<int> q;
    G->visit[0] = true;
    q.push(0);
    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        for (int i = 0; i < G->vertexnum; i++)
        {
            if (G->edgeList[tmp][i] && !G->visit[i])
            {
                G->visit[i] = true;
                q.push(i);
                cout << i << "Visited" << endl;
            }
        }
    }
}

int main()
{
    Graph G;
    BuildGraph(&G);
    BFS(&G);
    cout << endl;
    system("pause");
    return 0;
}

/* 
7 9
0 2 1
0 1 1
0 3 1
1 2 1
2 3 1
2 4 1
3 6 1
1 5 1
5 6 1
*/