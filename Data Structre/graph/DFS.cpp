/* 
通过邻接表实现DFS
*/

#include <iostream>
#include <stack>
using namespace std;

#define MaxVertexNum 10

struct EdgeNode
{
    int adjvex;
    EdgeNode *next;
};

struct VertexNode
{
    EdgeNode *firstedge;
};

struct Graph
{
    int vertexnum;
    int edgenum;
    VertexNode vertexList[MaxVertexNum];
    bool visit[MaxVertexNum];
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
        G->vertexList[i].firstedge = NULL;
        G->visit[i] = false;
    }
    // 输入权重信息
    for (int i = 0; i < G->edgenum; i++)
    {
        cout << "Please enter the Start number, end number" << endl;
        cin >> start >> end;
        //start-->end
        newnode = new EdgeNode;
        newnode->adjvex = end;
        newnode->next = G->vertexList[start].firstedge;
        G->vertexList[start].firstedge = newnode;
        // end-->start
        newnode = new EdgeNode;
        newnode->adjvex = start;
        newnode->next = G->vertexList[end].firstedge;
        G->vertexList[end].firstedge = newnode;
    }
}

void Print_Adjacency_Matrix(Graph G)
{
    for (int i = 0; i < G.vertexnum; i++)
    {
        cout << i << '\t';
        EdgeNode *p = G.vertexList[i].firstedge;
        while (p)
        {
            printf("adjvex:%d  ", p->adjvex);
            p = p->next;
        }
        cout << endl;
    }
}

void DFS(Graph *G)
{
    stack<int> s;
    s.push(0);
    G->visit[0] = true;
    while (!s.empty())
    {
        int tmp = s.top();
        EdgeNode *p = G->vertexList[tmp].firstedge;
        while (p)
        {
            if (G->visit[p->adjvex])
            {
                p = p->next;
            }
            else
            {
                cout << "-->" << p->adjvex;
                s.push(p->adjvex);
                G->visit[p->adjvex] = true;
                // 找到下一深度的点就不再周边广搜
                break;
            }
            // 周围没有待访问的点，出栈
            if (p == NULL)
            {
                s.pop();
            }
        }
    }
}

int main()
{
    Graph G;
    BuildGraph(&G);
    Print_Adjacency_Matrix(G);
    DFS(&G);
    cout << endl;
    system("pause");
    return 0;
}

/*  
9 10
0 1
0 7
1 2
1 4
7 5 
7 8
2 3
4 3
5 3
5 6
*/