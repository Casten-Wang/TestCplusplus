#include <iostream>
using namespace std;

int main()
{
    memcpy(b, a, 2);
    for (int i = 0; i < 2; i++)
    {
        cout << b[i];
    }

    system("pause");
    return 0;
}
