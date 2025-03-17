#include <iostream>
using namespace std;

int main()
{
    int a[] = {5, 22, 4, 59, 56, 331, 2};
    int n = 7;

    int count = 0;

    for (int i = 1; i < n - 1; i++)
    {
        if (a[i - 1] < a[i] && a[i] > a[i + 1])
        {
            count++;
            cout << i << " : " << a[i] << endl;
        }
    }
    cout << "count -> " << count << endl;

    return 0;
}