/*  
有权图的单源最短路径问题
*/

#include <iostream>
#include <queue>
using namespace std;

#define MaxVertexNum 10

struct Node
{
    int vertex;
    int dist;
};

struct Graph
{
    int edgenum;
    int vertexnum;
    int edgeList[MaxVertexNum][MaxVertexNum];
    bool visit[MaxVertexNum];
    int path[MaxVertexNum]; // 前驱结点
    int dist[MaxVertexNum]; // 从源点到其他各顶点当前最短路径长度
};

class mycomparison
{
public:
    bool operator()(const Node &a, Node &b)
    {
        return a.dist > b.dist;
    }
};

void BuildGraph(Graph *G)
{
    int start, end;
    cout << "Please enter the number of vertices and edges" << endl;
    cin >> G->vertexnum >> G->edgenum;
    // 图的权重初始化
    for (int i = 1; i <= G->vertexnum; i++)
    {
        G->visit[i] = false;
        G->path[i] = -1;
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
    }
    cout << endl;
}

void Dijkstra(Graph *G, int v)
{
    // 初始化
    G->visit[v] = true;
    G->dist[v] = 0;
    priority_queue<Node, vector<Node>, mycomparison> minheap;
    Node p;
    for (int i = 1; i <= G->vertexnum; i++)
    {
        if (G->edgeList[v][i])
        {
            G->dist[i] = G->edgeList[v][i];
            G->path[i] = v;
            p.dist = G->dist[i];
            p.vertex = i;
            minheap.push(p);
        }
    }
    while (!minheap.empty())
    {
        // 选出未访问顶点中dist最小的
        int minv = minheap.top().vertex;
        minheap.pop();
        G->visit[minv] = true;
        for (int i = 1; i <= G->vertexnum; i++)
        {
            if (G->edgeList[minv][i] && !G->visit[i] && G->dist[minv] + G->edgeList[minv][i] < G->dist[i])
            {
                G->dist[i] = G->dist[minv] + G->edgeList[minv][i];
                G->path[i] = minv;
                p.dist = G->dist[i];
                p.vertex = i;
                minheap.push(p);
            }
        }
    }
    cout << endl;
}

int main()
{
    Graph G;
    BuildGraph(&G);
    Dijkstra(&G, 1);
    cout << "distance" << endl;
    for (int i = 1; i <= G.vertexnum; i++)
    {
        cout << G.dist[i] << " ";
    }
    cout << endl;
    cout << "path" << endl;
    for (int i = 1; i <= G.vertexnum; i++)
    {
        cout << G.path[i] << " ";
    }
    system("pause");
    return 0;
}

/*  
7 12
1 2 2
1 4 1
2 4 3
2 5 10
4 5 2
4 3 2
3 1 4
3 6 5
4 6 8
4 7 4
5 7 6
7 6 1
*/