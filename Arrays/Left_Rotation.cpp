#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &a, int i, int j)
{
    while (i < j)
    {
        swap(a[i++], a[j--]);
    }
}

int main()
{
    vector<int> a = {1,2,3,4,5};
    
    int n = a.size();
    int k = 3;

    reverse(a, 0, k - 1);
    reverse(a, k, n - 1);
    reverse(a, 0, n - 1);

    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}