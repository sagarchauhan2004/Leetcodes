#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int a[5] = {1, 6, 3, 8, 9};
    int target = 14;

    map<int, int> mp;

    for (int i = 0; i < 5; i++)
    {
        int rem = target - a[i];

        if (mp.find(rem) == mp.end())
        {
            mp[a[i]] = i;
        }
        else
        {
            cout << mp[rem] << " " << i << endl;
        }
    }
    return 0;
}
