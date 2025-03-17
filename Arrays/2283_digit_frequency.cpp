#include <iostream>
using namespace std;

int main()
{
    string a = "1210";
    int count[10] = {0};
    for (int i = 0; i < a.length(); i++)
    {
        for (int j = 0; j < a.length(); j++)
        {
            if (count[j] - '0' == i)
            {
                count[j - '0']++;
            }
        }
    }
    for (int i = 0; i < a.length(); i++)
    {
        if (count[i] != a[i])
        {
            cout << "False" << endl;
            break;
        }
    }

    return 0;
}