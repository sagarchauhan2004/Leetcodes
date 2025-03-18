/*
A parentheses string is valid if and only if:

it is the empty string,

it can vve written as AB (A concatenated with B), where A and B are valid strings , or

it can ve written as (A) where A is a valid String.

You are given a parentheses string s. in one move, you can insert a parenthesis at any position of the string.

for example , if s = "()))".You can insert an opening parenthesis to be "(()))" or closing parenthesis to be "())))".

return the mininum number of moves required to make s valid.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minAddToMakeValue(string s)
    {
        int size = 0;
        int open = 0;

        for (char &ch : s)
        {
            if (ch == '(')
            {
                size++;
            }
            else if (size > 0)
            {
                size--;
            }
            else
            {
                open++;
            }
        }
        return open + size;
    }
};

int main()
{
    string s = "(()(";
    Solution sl;

    int ans = sl.minAddToMakeValue(s);

    cout << ans;
    return 0;
}