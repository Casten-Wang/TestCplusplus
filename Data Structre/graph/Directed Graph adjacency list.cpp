/* 
有向图邻接表
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
    VertexNode vertexList[MaxVertexNum];
    VertexNode inverseVertexList[MaxVertexNum];
};

void BuildGraph(Graph *G)
{
    int start, end, weight;
    EdgeNode *newnode;
    cout << "Please enter the number of vertices and edges" << endl;
    cin >> G->vertexnum >> G->edgenum;
    // 图的顶点数据
    for (int i = 0; i < G->vertexnum; i++)
    {
        cout << "Please enter the data of vertex" << i << endl;
        cin >> G->vertexList[i].data;
        G->vertexList[i].firstedge = NULL;
        G->inverseVertexList[i].data = G->vertexList[i].data;
        G->inverseVertexList[i].firstedge = NULL;
    }
    // 输入权重信息
    for (int i = 0; i < G->edgenum; i++)
    {
        cout << "Please enter the Start number, end number, weight" << endl;
        cin >> start >> end >> weight;
        //start-->end
        newnode = new EdgeNode;
        newnode->adjvex = end;
        newnode->weight = weight;
        newnode->next = G->vertexList[start].firstedge;
        G->vertexList[start].firstedge = newnode;
        // 逆邻接表
        newnode = new EdgeNode;
        newnode->adjvex = start;
        newnode->weight = weight;
        newnode->next = G->inverseVertexList[end].firstedge;
        G->inverseVertexList[end].firstedge = newnode;
    }
}

void Print_Adjacency_Matrix(Graph G)
{
    for (int i = 0; i < G.vertexnum; i++)
    {
        cout << G.vertexList[i].data << '\t';
        EdgeNode *p = G.vertexList[i].firstedge;
        while (p)
        {
            printf("adjvex:%d weight:%d  ", p->adjvex, p->weight);
            p = p->next;
        }
        cout << endl;
    }
    cout << endl;
    cout << "inverse adjacency list" << endl;
    for (int i = 0; i < G.vertexnum; i++)
    {
        cout << G.inverseVertexList[i].data << '\t';
        EdgeNode *p = G.inverseVertexList[i].firstedge;
        while (p)
        {
            printf("adjvex:%d weight:%d  ", p->adjvex, p->weight);
            p = p->next;
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