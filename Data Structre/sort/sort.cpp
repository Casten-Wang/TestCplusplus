// 所有排序模板

#include <iostream>
using namespace std;

typedef int ElementType;

// 函数声明
void BubbleSort(ElementType A[], int n);
void DirectInsertSort(ElementType A[], int n);
void BinaryInsertSort(ElementType A[], int n);

// 主函数入口
int main()
{

    ElementType A[8] = {49, 38, 65, 97, 76, 13, 27, 49};
    // 冒泡排序
    BubbleSort(A, 8);
    cout << "BubbleSort Results" << endl;
    for (ElementType it : A)
    {
        cout << it << " ";
    }
    cout << endl;
    // 直接插入排序
    // B[0] 为哨兵
    ElementType B[9] = {0, 49, 38, 65, 97, 76, 13, 27, 49};
    DirectInsertSort(B, 8);
    cout << "DirectInsertSort Results" << endl;
    for (int i = 1; i < 9; i++)
    {
        cout << B[i] << " ";
    }
    cout << endl;
    // 折半插入排序
    // C[0] 为哨兵
    ElementType C[9] = {0, 49, 38, 65, 97, 76, 13, 27, 49};
    BinaryInsertSort(C, 8);
    cout << "BinaryInsertSort Results" << endl;
    for (int i = 1; i < 9; i++)
    {
        cout << C[i] << " ";
    }
    system("pause");
    return 0;
}

// 冒泡排序
void BubbleSort(ElementType A[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        // 判断本趟冒泡是否发生交换的标志
        bool flag = false;
        for (int j = n - 1; j > i; j--)
        {
            if (A[j - 1] > A[j])
            {
                swap(A[j - 1], A[j]);
                flag = true;
            }
        }
        if (!flag)
        {
            break;
        }
    }
}

// 直接插入排序
void DirectInsertSort(ElementType A[], int n)
{
    int i, j;
    for (i = 2; i <= n; i++)
    {
        // 看是否比序列大，如果大就不用移动位置，反之要进入循环移动位置
        if (A[i] < A[i - 1])
        {
            // 放置哨兵
            A[0] = A[i];
            for (j = i - 1; A[j] > A[0]; j--)
            {
                // 向后移位
                A[j + 1] = A[j];
            }
            // 将哨兵里元素放到属于他的位置
            A[j + 1] = A[0];
        }
    }
}

// 折半插入排序
void BinaryInsertSort(ElementType A[], int n)
{
    int i, j, mid, low, high;
    for (int i = 2; i <= n; i++)
    {
        A[0] = A[i];
        low = 1, high = i - 1;
        // 二分查找定位置
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (A[mid] > A[0])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // 最后会以high=low-1结束，所以high指向元素就是应该插入元素的前一个元素
        // 那么high+1表示的就是应该插入元素的位置
        for (j = i - 1; j >= high + 1; j--)
        {
            A[j + 1] = A[j];
        }
        A[high + 1] = A[0];
    }
}
