/* 
无向图邻接表
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define MaxVertexNum 100
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
    vertexType vertexList[MaxVertexNum];
};

void BuildGraph(Graph *G)
{
    int start, end;
    cout << "Please enter the number of vertices and edges" << endl;
    cin >> G->vertexnum >> G->edgenum;
    // 图的权重初始化
    for (int i = 0; i < G->vertexnum; i++)
    {
        for (int j = 0; j < G->vertexnum; j++)
        {
            G->edgeList[i][j] = 0;
        }
    }
    // 图的顶点数据
    for (int i = 0; i < G->vertexnum; i++)
    {
        cout << "Please enter the data of vertex" << i + 1 << endl;
        cin >> G->vertexList[i];
    }
    // 输入权重信息
    for (int i = 0; i < G->edgenum; i++)
    {
        cout << "Please enter the Start number, end number, weight" << endl;
        cin >> start >> end;
        cin >> G->edgeList[start - 1][end - 1];
    }
    cout << endl;
}

void Print_Adjacency_Matrix(Graph G)
{
    for (int i = 0; i < G.vertexnum; i++)
    {
        for (int j = 0; j < G.vertexnum; j++)
        {
            cout << G.edgeList[i][j] << '\t';
        }
        cout << endl;
    }
}

int main()
{
    Graph G;
    BuildGraph(&G);
    Print_Adjacency_Matrix(G);
    cout << endl;
    system("pause");
    return 0;
}