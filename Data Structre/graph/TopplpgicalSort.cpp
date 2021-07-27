/* 
有向图邻接表实现拓扑排序
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MaxVertexNum 10
typedef int weightType;  // 权重数据类型
typedef char vertexType; // 顶点数据类型

struct EdgeNode
{
    int adjvex;
    weightType weight;
    EdgeNode *next;
};

struct VertexNode
{
    vertexType data;
    EdgeNode *firstedge;
};

struct Graph
{
    int vertexnum;
    int edgenum;
    VertexNode vertexList[MaxVertexNum];
};

void BuildGraph(Graph *G)
{
    int start, end, weight;
    EdgeNode *newnode;
    cout << "Please enter the number of vertices and edges" << endl;
    cin >> G->vertexnum >> G->edgenum;
    // 图的顶点数据
    for (int i = 1; i <= G->vertexnum; i++)
    {
        // 输入顶点名
        // cout << "Please enter the data of vertex" << i << endl;
        // cin >> G->vertexList[i].data;
        G->vertexList[i].firstedge = NULL;
    }
    // 输入权重信息
    for (int i = 1; i <= G->edgenum; i++)
    {
        cout << "Please enter the Start number, end number" << endl;
        cin >> start >> end;
        //start-->end
        newnode = new EdgeNode;
        newnode->adjvex = end;
        // newnode->weight = weight;
        newnode->next = G->vertexList[start].firstedge;
        G->vertexList[start].firstedge = newnode;
    }
}

void TopologicalSort(Graph *G)
{
    // 初始化队列
    queue<int> q;
    // 初始化入度统计表
    vector<int> indegree(G->vertexnum + 1, 0);
    for (int i = 1; i <= G->vertexnum; i++)
    {
        for (EdgeNode *j = G->vertexList[i].firstedge; j; j = j->next)
        {
            indegree[j->adjvex]++;
        }
    }
    // 将所有入度为0的顶点入队
    for (int i = 1; i <= G->vertexnum; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    // 输出的顶点数
    int count = 0;
    // 开始搜索
    while (count < G->vertexnum)
    {
        count++;
        int v = q.front();
        cout << v << "  ";
        q.pop();
        // 将v所指向的顶点入度减一
        for (EdgeNode *w = G->vertexList[v].firstedge; w; w = w->next)
        {
            if (--indegree[w->adjvex] == 0)
            {
                q.push(w->adjvex);
            }
        }
    }
}

int main()
{
    Graph G;
    BuildGraph(&G);
    TopologicalSort(&G);
    cout << endl;
    system("pause");
    return 0;
}

/*
8 10
1 2
1 3
2 3
3 8
3 7
7 8
5 3
4 5
5 6
6 7
*/