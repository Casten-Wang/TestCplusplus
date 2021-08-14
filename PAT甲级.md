# PAT甲级

## 参考资料

[题目列表 (pintia.cn)](https://pintia.cn/problem-sets/994805342720868352/problems/type/7)

[柳婼CSDN博客](https://blog.csdn.net/liuchuo?spm=1001.2014.3001.5509)

## 目录

[TOC]



## 1001. A+B Format (20分)

> Calculate *a*+*b* and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).
>
> ### Input Specification:
>
> Each input file contains one test case. Each case contains a pair of integers *a* and *b* where −106≤*a*,*b*≤106. The numbers are separated by a space.
>
> ### Output Specification:
>
> For each test case, you should output the sum of *a* and *b* in one line. The sum must be written in the standard format.
>
> ### Sample Input:
>
> ```in
> -1000000 9
> 
> 结尾无空行
> ```
>
> ### Sample Output:
>
> ```out
> -999,991
> 
> 结尾无空行
> ```

```c
#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    string s = to_string(a + b);
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        cout << s[i];
        if (s[i] == '-')
        {
            continue;
        }
        if ((len - 1 - i) % 3 == 0 && i != len - 1)
            cout << ",";
    }
    return 0;
}
```

我要麻了，第一题还出错，写了半小时。开始想复杂了，用了栈和整数求余。其实很简单，要注意的点就是算逗号的时候需要倒置求余。

## 1002. A+B for Polynomials (25分)

> This time, you are supposed to find *A*+*B* where *A* and *B* are two polynomials.
>
> ### Input Specification:
>
> Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:
>
> K N~1~ a~N1~ N~2~ a~N2~ ... N~K~ a~NK~
>
> where K is the number of nonzero terms in the polynomial, N~i~ and aN~i~ (i=1,2,⋯,K) are the exponents and coefficients, respectively. It is given that 1≤K≤10，0≤N~K~<⋯<N~2~<N~1~≤1000.
>
> ### Output Specification:
>
> For each test case you should output the sum of *A* and *B* in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.
>
> ### Sample Input:
>
> ```in
> 2 1 2.4 0 3.2
> 2 2 1.5 1 0.5
> 结尾无空行
> ```
>
> ### Sample Output:
>
> ```out
> 3 2 1.5 1 2.9 0 3.2
> 
> 结尾无空行
> ```

```c
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
    int z;
    float x;
};

bool compare(node A, node B)
{
    return A.z > B.z;
}

int main()
{
    vector<node> A, B, C;
    node tmp;
    int a, b;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        cin >> tmp.z >> tmp.x;
        A.push_back(tmp);
    }
    cin >> b;
    for (int i = 0; i < b; i++)
    {
        cin >> tmp.z >> tmp.x;
        B.push_back(tmp);
    }
    // 排序
    sort(A.begin(), A.end(), compare);
    sort(B.begin(), B.end(), compare);
    // 双指针法
    int i, j;
    for (i = 0, j = 0; i < a && j < b;)
    {
        if (A[i].z > B[j].z)
        {
            tmp = A[i++];
            C.push_back(tmp);
        }
        else if (A[i].z < B[j].z)
        {
            tmp = B[j++];
            C.push_back(tmp);
        }
        else
        {
            tmp.z = A[i].z;
            tmp.x = A[i++].x + B[j++].x;
            // 系数为零就抵消了
            if (tmp.x)
            {
            C.push_back(tmp);
            }
            
        }
    }
    // 余值按序插入，2个while只有一个会被执行
    while (i < a)
    {
        tmp = A[i++];
        C.push_back(tmp);
    }
    while (j < b)
    {
        tmp = B[j++];
        C.push_back(tmp);
    }
    // 输出
    cout << C.size();
    for (node it : C)
    {
        printf(" %d %.1f", it.z, it.x);
    }
    system("pause");
    return 0;
}
```

受最近数据结构的影响，思维还没转变过来。想到的是传统的结构体解法，合并多项式借用了归并排序的思想，先将2个多项式降序排序，然后双指针法合并。卡壳的主要原因是没有考虑多项式相加为零要剔除的情况。

```c
#include <iostream>
using namespace std;

int main()
{
    double N[1005] = {0};
    for (int i = 0; i < 2; i++)
    {
        int len;
        cin >> len;
        for (int k = 0; k < len; k++)
        {
            int z;
            double x;
            cin >> z >> x;
            N[z] += x;
        }
    }
    int count = 0;
    for (int i = 0; i <= 1000; i++)
    {
        if (N[i] != 0)
        {
            count++;
        }
    }
    cout << count;
    for (int i = 1000; i >= 0; i--)
    {
        if (N[i] != 0)
        {
            printf(" %d %.1f", i, N[i]);
        }
    }
    return 0;
}
```

数组下标表示指数，数组元素表示系数。简单明了。

## 1003. Emergency (25分)

> As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.
>
> ### Input Specification:
>
> Each input file contains one test case. For each test case, the first line contains 4 positive integers: *N* (≤500) - the number of cities (and the cities are numbered from 0 to *N*−1), *M* - the number of roads, *C*1 and *C*2 - the cities that you are currently in and that you must save, respectively. The next line contains *N* integers, where the *i*-th integer is the number of rescue teams in the *i*-th city. Then *M* lines follow, each describes a road with three integers *c*1, *c*2 and *L*, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from *C*1 to *C*2.
>
> ### Output Specification:
>
> For each test case, print in one line two numbers: the number of different shortest paths between *C*1 and *C*2, and the maximum amount of rescue teams you can possibly gather. All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.
>
> ### Sample Input:
>
> ```in
> 5 6 0 2
> 1 2 1 5 3
> 0 1 1
> 0 2 2
> 0 3 1
> 1 2 1
> 2 4 1
> 3 4 1
> 
> 结尾无空行
> ```
>
> ### Sample Output:
>
> ```out
> 2 4
> 
> 结尾无空行
> ```

![image-20210806214228028](https://raw.githubusercontent.com/Casten-Wang/Pic/master/20210806214235.png)

```c
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node
{
    int vertex;
    int dist;
};

class mycomparison
{
public:
    bool operator()(const node &a, node &b)
    {
        return a.dist > b.dist;
    }
};

int main()
{
    // cin
    int N, M, c1, c2;
    cin >> N >> M >> c1 >> c2;
    int rescueteams[N];
    for (int i = 0; i < N; i++)
    {
        cin >> rescueteams[i];
    }
    int G[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            G[i][j] = 0;
        }
    }
    for (int i = 0; i < M; i++)
    {
        int start, end, weight;
        cin >> start >> end >> weight;
        G[start][end] = weight;
        G[end][start] = weight;
    }
    vector<bool> visit(N, false);
    vector<int> teams(N, 0);
    vector<int> dist(N, 1e9);
    vector<int> num(N, 1);
    priority_queue<node, vector<node>, mycomparison> q;
    node tmp;
    // Dijkstra
    visit[c1] = true;
    dist[c1] = 0;
    teams[c1] = rescueteams[c1];
    for (int i = 0; i < N; i++)
    {
        if (G[c1][i])
        {
            dist[i] = G[c1][i];
            teams[i] = teams[c1] + rescueteams[i];
            tmp.dist = dist[i];
            tmp.vertex = i;
            q.push(tmp);
        }
    }
    while (!q.empty())
    {
        int minv = q.top().vertex;
        visit[minv] = true;
        q.pop();
        for (int i = 0; i < N; i++)
        {
            if (!visit[i] && G[minv][i] && dist[minv] + G[minv][i] <= dist[i])
            {
                if (dist[minv] + G[minv][i] == dist[i])
                {
                    teams[i] = max(teams[i], teams[minv] + rescueteams[i]);
                    num[i]++;
                }
                else
                {
                    teams[i] = teams[minv] + rescueteams[i];
                }

                dist[i] = dist[minv] + G[minv][i];
                tmp.dist = dist[i];
                tmp.vertex = i;
                q.push(tmp);
            }
        }
    }
    cout << num[c2] << " " << teams[c2];
    return 0;
}
```

本题主要考察Dijkstra算法，我通过最小堆实现。这道题卡了挺久，主要是没有很好的理解题意。题目要输出的是最短路径数量和最大救援队伍数。对应要修改Dijkstra模板的部分为 `dist[minv] + G[minv][i] <= dist[i]`，在判断通过当前最短路径点经过当前点时是否小于等于当前点原先储存的最短路径。特别要注意等于的情况，如果等于，最短路径数量加一，救援队伍数 `max(teams[i], teams[minv] + rescueteams[i])`，比较先前最短路径下的救援队伍数和当前路径下的救援队伍数，输出最大值。

## 1004. Counting Leaves (30分)

> A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.
>
> ### Input Specification:
>
> Each input file contains one test case. Each case starts with a line containing 0<*N*<100, the number of nodes in a tree, and *M* (<*N*), the number of 	. Then *M* lines follow, each in the format:
>
> ```
> ID K ID[1] ID[2] ... ID[K]
> ```
>
> where `ID` is a two-digit number representing a given non-leaf node, `K` is the number of its children, followed by a sequence of two-digit `ID`'s of its children. For the sake of simplicity, let us fix the root ID to be `01`.
>
> The input ends with *N* being 0. That case must NOT be processed.
>
> ### Output Specification:
>
> For each test case, you are supposed to count those family members who have no child **for every seniority level** starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.
>
> The sample case represents a tree with only 2 nodes, where `01` is the root and `02` is its only child. Hence on the root `01` level, there is `0` leaf node; and on the next level, there is `1` leaf node. Then we should output `0 1` in a line.
>
> ### Sample Input:
>
> ```in
> 2 1
> 01 1 02
> 
> 结尾无空行
> ```
>
> ### Sample Output:
>
> ```out
> 0 1
> 
> 结尾无空行
> ```

```c
#include <iostream>
#include <vector>
using namespace std;

int maxlevel = 1;
int leaf[100] = {0};
vector<int> P[100];

void DFS(int parent, int level)
{
    maxlevel = max(maxlevel, level);
    // 如果该点没有孩子结点
    if (!P[parent].size())
    {
        leaf[level]++;
        return;
    }
    // 依次搜索该点的每一个孩子结点
    for (int i = 0; i < P[parent].size(); i++)
    {
        DFS(P[parent][i], level + 1);
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int parent, k, id;
        cin >> parent >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> id;
            P[parent].push_back(id);
        }
    }
    DFS(1, 1);
    cout << leaf[1];
    for (int i = 2; i <= maxlevel; i++)
    {
        cout << " " << leaf[i];
    }
    return 0;
}
```

简单的深度优先搜索，需要注意的是数组存放孩子节点。每次递归要更新树的最大深度。

## 1005. Spell It Right (20分)

> Given a non-negative integer *N*, your task is to compute the sum of all the digits of *N*, and output every digit of the sum in English.
>
> ### Input Specification:
>
> Each input file contains one test case. Each case occupies one line which contains an *N* (≤10^100^).
>
> ### Output Specification:
>
> For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.
>
> ### Sample Input:
>
> ```in
> 12345
> 
> 结尾无空行
> ```
>
> ### Sample Output:
>
> ```out
> one five
> 
> 结尾无空行
> ```

```c
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string words;
    cin >> words;
    int sum = 0;
    for (char it : words)
    {
        sum += atoi(&it);
    }
    string hash[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string res = to_string(sum);
    cout << hash[res[0] - '0'];
    for (int i = 1; i < res.size(); i++)
    {
        int num = res[i] - '0';
        cout << " " << hash[num];
    }
    return 0;
}
```

## 1006. Sign In and Sign Out (25分)

> At the beginning of every day, the first person who signs in the computer room will unlock the door, and the last one who signs out will lock the door. Given the records of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day.
>
> ### Input Specification:
>
> Each input file contains one test case. Each case contains the records for one day. The case starts with a positive integer *M*, which is the total number of records, followed by *M* lines, each in the format:
>
> ```
> ID_number Sign_in_time Sign_out_time
> ```
>
> where times are given in the format `HH:MM:SS`, and `ID_number` is a string with no more than 15 characters.
>
> ### Output Specification:
>
> For each test case, output in one line the ID numbers of the persons who have unlocked and locked the door on that day. The two ID numbers must be separated by one space.
>
> Note: It is guaranteed that the records are consistent. That is, the sign in time must be earlier than the sign out time for each person, and there are no two persons sign in or out at the same moment.
>
> ### Sample Input:
>
> ```in
> 3
> CS301111 15:30:28 17:00:10
> SC3021234 08:00:00 11:25:25
> CS301133 21:45:00 21:58:40
> 
> 结尾无空行
> ```
>
> ### Sample Output:
>
> ```out
> SC3021234 CS301133
> 
> 结尾无空行
> ```

```c
#include <iostream>
using namespace std;

struct Time
{
    int hour;
    int minute;
    int second;
};

struct Person
{
    string id;
    Time in_time;
    Time out_time;
};

int main()
{
    int M;
    cin >> M;
    Person p;
    int early_in_time = 1e9, late_out_time = 0;
    string early_person, late_person;
    for (int i = 0; i < M; i++)
    {
        cin >> p.id;
        scanf("%d:%d:%d", &p.in_time.hour, &p.in_time.minute, &p.in_time.second);
        scanf("%d:%d:%d", &p.out_time.hour, &p.out_time.minute, &p.out_time.second);
        int intime = (p.in_time.hour * 60 + p.in_time.minute) * 60 + p.in_time.second;
        int outtime = (p.out_time.hour * 60 + p.out_time.minute) * 60 + p.out_time.second;
        if (intime < early_in_time)
        {
            early_in_time = intime;
            early_person = p.id;
        }
        if (outtime > late_out_time)
        {
            late_out_time = outtime;
            late_person = p.id;
        }
    }
    cout << early_person << " " << late_person;
    return 0;
}
```

很简单的题，但我的代码写的特别烂。完全没有必要写这么复杂，还结构里嵌套了结构，要搞清楚一点，求的其实是时间戳，何况是同一天的，只需要考虑一共占用了多少秒，再依次比较求出最值即可。感觉陷入了一种思维惯性，不仅仅要考虑优化算法，写法的优化也是不可缺少的。

## 1007. Maximum Subsequence Sum (25分)

> Given a sequence of *K* integers { *N*1, *N*2, ..., *N**K* }. A continuous subsequence is defined to be { *N**i*, *N**i*+1, ..., *N**j* } where 1≤*i*≤*j*≤*K*. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.
>
> Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.
>
> ### Input Specification:
>
> Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer *K* (≤10000). The second line contains *K* numbers, separated by a space.
>
> ### Output Specification:
>
> For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices *i* and *j* (as shown by the sample case). If all the *K* numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.
>
> ### Sample Input:
>
> ```in
> 10
> -10 1 2 3 4 -5 -23 3 7 -21
> 
> 结尾无空行
> ```
>
> ### Sample Output:
>
> ```out
> 10 1 4
> 
> 结尾无空行
> ```

```c
#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    // 最大子序列和：在线处理,直接累加，如果累加到当前的和为负数，置当前值或0 时间复杂度N
    int sum = 0, maxsum = -1, start = 0, end = N - 1, index = 0;
    for (int i = 0; i < N; i++)
    {
        sum += A[i];
        if (sum < 0)
        {
            index = i + 1;
            sum = 0;
        }
        else if (sum > maxsum)
        {
            maxsum = sum;
            start = index;
            end = i;
        }
    }
    if (maxsum < 0)
    {
        maxsum = 0;
    }
    cout << maxsum << " " << A[start] << " " << A[end];
    return 0;
}
```

时间复杂度：==$O(n)$==，直接一遍遍历，更新最大值，如果 $sum<0$，说明前面这段对我的子序列来说，只会产生负反馈，所以直接剔除。

卡壳的主要原因是英文水平不行，又或者说没有仔细阅读题目。==together with the first and the last numbers of the maximum subsequence==，好好看看它的意思，求的是元素而不是索引。

## 1008. Elevator (20分)

> The highest building in our city has only one elevator. A request list is made up with *N* positive numbers. The numbers denote at which floors the elevator will stop, in specified order. It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. The elevator will stay for 5 seconds at each stop.
>
> For a given request list, you are to compute the total time spent to fulfill the requests on the list. The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.
>
> ### Input Specification:
>
> Each input file contains one test case. Each case contains a positive integer *N*, followed by *N* positive numbers. All the numbers in the input are less than 100.
>
> ### Output Specification:
>
> For each test case, print the total time on a single line.
>
> ### Sample Input:
>
> ```in
> 3 2 3 1
> 
> 结尾无空行
> ```
>
> ### Sample Output:
>
> ```out
> 41
> 
> 结尾无空行
> ```

