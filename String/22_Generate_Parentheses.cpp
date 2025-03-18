/*

22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.


Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]


Constraints:

1 <= n <= 8
*/

#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<string> result;
    void solve(string &cur, int open, int close, int n)
    {
        if (cur.length() == 2 * n)
        {
            result.push_back(cur);
            return;
        }
        if (open < n)
        {
            cur.push_back('(');
            solve(cur, open + 1, close, n);
            cur.pop_back();
        }
        if (close < open)
        {
            cur.push_back(')');
            solve(cur, open, close + 1, n);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n)
    {
        string cur = "";

        solve(cur, 0, 0, n);

        return result;
    }
};

int main()
{
    Solution sl;

    vector<string> ans = sl.generateParenthesis(3);
    for (string str : ans)
    {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}