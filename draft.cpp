#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int a[2] = {85, 2};
    int b[2];
    memcpy(b, a, 2);
    for (int i = 0; i < 2; i++)
    {
        cout << b[i];
    }

    system("pause");
    return 0;
}
