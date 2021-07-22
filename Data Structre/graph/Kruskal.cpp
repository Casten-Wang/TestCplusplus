/* 
最小生成树 Kruskal算法
*/

#include <iostream>
#include <queue>
using namespace std;

#define MaxVertexNum 10
#define infinity 1e5
typedef int weightType;  // 权重数据类型
typedef char vertexType; // 顶点数据类型

// 最小堆里需要边的数据
struct MyEdge
{
    int v1;
    int v2;
    int weight;
};

// 优先队列排序函数
class mycomparison
{
public:
    bool operator()(const MyEdge &a, MyEdge &b)
    {
        return a.weight > b.weight;
    }
};

// 邻接表建立
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
        cout << "Please enter the Start number, end number, weight" << endl;
        cin >> start >> end >> weight;
        //start-->end
        newnode = new EdgeNode;
        newnode->adjvex = end;
        newnode->weight = weight;
        newnode->next = G->vertexList[start].firstedge;
        G->vertexList[start].firstedge = newnode;
        // end-->start
        newnode = new EdgeNode;
        newnode->adjvex = start;
        newnode->weight = weight;
        newnode->next = G->vertexList[end].firstedge;
        G->vertexList[end].firstedge = newnode;
    }
    cout << endl;
}

// 并查集寻找根节点
int Find_set(int *parent, int x)
{
    for (; parent[x] != x; x = parent[x])
    {
        ;
    }
    return x;
}

// Kruskal算法
void Kruskal(Graph *G)
{
    // 初始化收录的边数
    int ECount = 0;
    // 初始化最小堆
    priority_queue<MyEdge, vector<MyEdge>, mycomparison> minheap;
    // 边入堆
    MyEdge N;
    for (int i = 1; i <= G->vertexnum; i++)
    {
        EdgeNode *p = G->vertexList[i].firstedge;
        // 无向图双向边是重复的，所以只收录一条，即v1小于v2的边
        while (p)
        {
            if (i < p->adjvex)
            {
                N.v1 = i;
                N.v2 = p->adjvex;
                N.weight = p->weight;
                // 入堆
                minheap.push(N);
            }
            p = p->next;
        }
    }
    // 初始化并查集
    int parent[G->vertexnum + 1];
    for (int i = 1; i <= G->vertexnum; i++)
    {
        // 每个子集的根节点设为自身
        parent[i] = i;
    }
    // 当收集到的边等于顶点数减一时，就可以构成生成树，要退出循环
    while (ECount < G->vertexnum - 1)
    {
        MyEdge tmp = minheap.top();
        minheap.pop();
        int root1 = Find_set(parent, tmp.v1);
        int root2 = Find_set(parent, tmp.v2);
        // 如果相等，说明二者属于同一集合，会构成回路
        if (root1 == root2)
        {
            continue;
        }
        // 输出选择的边
        cout << tmp.v1 << " " << tmp.v2 << endl;
        // 合并子集
        parent[root2] = root1;
        // 收录的边数加一
        ECount++;
    }
}

int main()
{
    Graph G;
    BuildGraph(&G);
    Kruskal(&G);
    cout << endl;
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