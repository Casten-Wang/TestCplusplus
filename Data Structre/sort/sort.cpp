// 所有排序模板

#include <iostream>
using namespace std;

typedef int ElementType;

// 函数声明
void BubbleSort(ElementType A[], int n);
void DirectInsertSort(ElementType A[], int n);
void BinaryInsertSort(ElementType A[], int n);
void ShellSort(ElementType A[], int n);
int Partition(ElementType A[], int low, int high);
void QuickSort(ElementType A[], int low, int high);
void SelectSort(ElementType A[], int n);
void HeapSort(ElementType A[], int len);
void BuildMaxHeap(ElementType A[], int len);
void HeadAdjust(ElementType A[], int k, int len);
int N = 7;
ElementType *B = new int[N];
void Merge(ElementType A[], int low, int mid, int high);
void MergeSort(ElementType A[], int low, int high);

// 主函数入口
int main()
{
    // 冒泡排序
    ElementType A[8] = {49, 38, 65, 97, 76, 13, 27, 49};
    BubbleSort(A, 8);
    cout << "BubbleSort Results" << endl;
    for (ElementType it : A)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << endl;
    // 直接插入排序
    // B[0]为哨兵
    ElementType B[9] = {0, 49, 38, 65, 97, 76, 13, 27, 49};
    DirectInsertSort(B, 8);
    cout << "DirectInsertSort Results" << endl;
    for (int i = 1; i < 9; i++)
    {
        cout << B[i] << " ";
    }
    cout << endl;
    cout << endl;
    // 折半插入排序
    // C[0]为哨兵
    ElementType C[9] = {0, 49, 38, 65, 97, 76, 13, 27, 49};
    BinaryInsertSort(C, 8);
    cout << "BinaryInsertSort Results" << endl;
    for (int i = 1; i < 9; i++)
    {
        cout << C[i] << " ";
    }
    cout << endl;
    cout << endl;
    // 希尔排序
    // D[0]为暂存单元
    ElementType D[11] = {0, 49, 38, 65, 97, 76, 13, 27, 49, 55, 4};
    BinaryInsertSort(D, 10);
    cout << "ShellSort Results" << endl;
    for (int i = 1; i < 11; i++)
    {
        cout << D[i] << " ";
    }
    cout << endl;
    cout << endl;
    // 快速排序
    ElementType E[8] = {49, 38, 65, 97, 76, 13, 27, 49};
    QuickSort(E, 0, 7);
    cout << "QuickSort Results" << endl;
    for (ElementType it : E)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << endl;
    // 简单选择排序
    ElementType F[8] = {49, 38, 65, 97, 76, 13, 27, 49};
    SelectSort(F, 8);
    cout << "SelectSort Results" << endl;
    for (ElementType it : F)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << endl;
    // 堆排序
    ElementType G[9] = {-1, 53, 17, 78, 9, 45, 65, 87, 32};
    HeapSort(G, 8);
    cout << "HeapSort Results" << endl;
    for (int i = 1; i < 9; i++)
    {
        cout << G[i] << " ";
    }
    cout << endl;
    cout << endl;
    // 归并排序
    ElementType H[7] = {49, 38, 65, 97, 76, 13, 27};
    SelectSort(H, 7);
    cout << "MergeSort Results" << endl;
    for (ElementType it : H)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << endl;

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

// 希尔排序
void ShellSort(ElementType A[], int n)
{
    // 记录步长
    for (int dk = n / 2; dk >= 1; dk = dk / 2)
    {
        for (int i = dk + 1; i <= n; i++)
        {
            if (A[i] < A[i - dk])
            {
                A[0] = A[i];
                int j;
                for (j = i - dk; A[0] < A[j] && j > 0; j -= dk)
                {
                    A[j + dk] = A[j];
                }
                A[j + dk] = A[0];
            }
        }
    }
}

// 快速排序
void QuickSort(ElementType A[], int low, int high)
{
    // 当子序列只剩一个元素时，pivot-1=low，这时high=low，函数结束
    if (low < high)
    {
        // 划分得到枢轴点位置
        int pivotpos = Partition(A, low, high);
        QuickSort(A, low, pivotpos - 1);
        QuickSort(A, pivotpos + 1, high);
    }
}

// 快速排序划分操作
int Partition(ElementType A[], int low, int high)
{
    // 选取第一个元素为枢轴点
    ElementType pivot = A[low];
    while (low < high)
    {
        // 循环找从右向左小于pivot的元素
        while (A[high] >= pivot && high > low)
        {
            high--;
        }
        // 找到该元素将该元素移到左端
        A[low] = A[high];
        while (A[low] <= pivot && high > low)
        {
            low++;
        }
        // 将比枢轴大的元素移到右端
        A[high] = A[low];
    }
    // 此时low=high，存放枢轴元素的值
    A[low] = pivot;
    return low;
}

// 简单选择排序
void SelectSort(ElementType A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int j, min = i;
        for (j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(A[i], A[min]);
        }
    }
}

// 堆排序
void HeapSort(ElementType A[], int len)
{
    BuildMaxHeap(A, len);
    for (int i = len; i > 1; i--)
    {
        // 将根结点与末尾结点交换位置，那么最大元素就被移到数组最后面
        swap(A[i], A[1]);
        // 同时调整堆的时候只对前面i-1元素进行，这样影响不到后面的已排好元素
        HeadAdjust(A, 1, i - 1);
    }
}

// 建堆
void BuildMaxHeap(ElementType A[], int len)
{
    for (int i = len / 2; i > 0; i--)
    {
        HeadAdjust(A, i, len);
    }
}

// 调整堆
void HeadAdjust(ElementType A[], int k, int len)
{
    // A[0]暂时存放子树的根结点
    A[0] = A[k];
    for (int i = 2 * k; i <= len; i *= 2)
    {
        // i如果等于len则没有右子树，也就没有比较左右子树的必要了
        if (i < len && A[i] < A[i + 1])
        {
            i++;
        }
        if (A[i] <= A[0])
        {
            break;
        }
        else
        {
            // 将A[i]复制到父节点
            A[k] = A[i];
            // 修改k，用以定位子树根结点应该放置的位置
            k = i;
        }
    }
    A[k] = A[0];
}

// 归并排序
void MergeSort(ElementType A[], int low, int high)
{
    // 划分子序列，分到每个子序列长度为1
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        Merge(A, low, mid, high);
    }
}

// 归并操作
void Merge(ElementType A[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k;
    // 把子序列所有元素复制到B数组
    for (int k = low; k <= high; k++)
    {
        B[k] = A[k];
    }

    for (k = low; i <= mid && j <= high; k++)
    {
        // 两个子序列相互比较，当一个序列的元素被安置完后
        // 另外一个序列的剩余元素肯定是大于且有序的，直接顺序插入
        if (B[i] < B[j])
        {
            A[k] = B[i++];
        }
        else
        {
            A[k] = B[j++];
        }
    }
    // 如果第一个表没有检测完，复制
    while (i <= mid)
    {
        A[k++] = B[i++];
    }
    // 同理
    while (j <= high)
    {
        A[k++] = B[j++];
    }
    // 注：只有一个while会执行
}
