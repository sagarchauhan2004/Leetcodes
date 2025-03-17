#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findNthDigit(int n)
    {

        int length = 1;
        long long count = 9;
        long long start = 1;

        while (n > length * count)
        {
            n -= length * count;
            length++;
            count *= 10;
            start *= 10;
        }

        start += (n - 1) / length;
        string s = to_string(start);
        long long ans = s[(n - 1) % length] - '0';
        return ans;
    }
};

int main()
{
    Solution sl;
    int n = 23;
    cout << sl.findNthDigit(n) << endl;

    return 0;
}
