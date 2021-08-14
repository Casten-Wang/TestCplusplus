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
    system("pause");
    return 0;
}