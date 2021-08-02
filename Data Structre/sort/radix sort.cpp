#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

// 获得一个数的各个位上的数字
int GetDigit(int X, int D)
{
    // 默认次位D=1, 主位D<=MaxDigit
    int d, i;
    for (i = 1; i <= D; i++)
    {
        d = X % 10;
        X /= 10;
    }
    return d;
}

int main()
{
    // 基数
    int radix = 10;
    // 建立桶
    node *bucket[radix];
    // 初始化待排序数组
    int A[10] = {278, 109, 63, 930, 589, 184, 505, 269, 8, 83};
    node *list = NULL;
    node *p;
    for (int i = 0; i < 10; i++)
    {
        node *tmp = new node;
        tmp->data = A[i];
        tmp->next = NULL;
        if (list == NULL)
        {
            list = tmp;
            p = list;
        }
        else
        {
            p->next = tmp;
            p = p->next;
        }
    }
    // 开始排序，对每一位进行处理
    for (int i = 1; i <= 3; i++)
    {
        // 清空桶
        for (int i = 0; i < radix; i++)
        {
            bucket[i] = NULL;
        }
        p = list;
        node *tmp;
        // 分配
        while (p)
        {
            tmp = p;
            p = p->next;
            int k = GetDigit(tmp->data, i);
            if (bucket[k] == NULL)
            {
                bucket[k] = tmp;
            }
            else
            {
                node *q = bucket[k];
                while (q->next)
                {
                    q = q->next;
                }
                q->next = tmp;
            }
            tmp->next = NULL;
        }
        // 收集
        list = NULL;
        for (int j = 0; j < radix; j++)
        {
            if (bucket[j] == NULL)
            {
                continue;
            }
            // 链表首指针定位
            if (bucket[j] && list == NULL)
            {
                list = bucket[j];
                p = list;
                continue;
            }
            // 此时p任指向上一个存在的桶
            while (p->next)
            {
                p = p->next;
            }
            // 如现在的桶存在，让上一个桶的最后一个结点指过来
            p->next = bucket[j];
        }
        // 打印
        cout << i << " trip: ";
        p = list;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
