/*
44. Wildcard Matching
Hard
Topics
Companies
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
*/

#include <iostream>
using namespace std;

class Solution
{
public:
    bool solve(string &str, string &pattern, int i, int j)
    {
        if (i < 0 && j < 0)
        {
            return true;
        }
        if (i >= 0 && j < 0)
        {
            return false;
        }
        if (i < 0 && j >= 0)
        {
            for (int k = 0; k <= j; k++)
            {
                if (pattern[k] != '*')
                {
                    return false;
                }
            }
            return true;
        }

        if (str[i] == pattern[j] || pattern[j] == '?')
        {
            return solve(str, pattern, i - 1, j - 1);
        }
        else if (pattern[j] == '*')
        {
            return (solve(str, pattern, i - 1, j) || solve(str, pattern, i, j - 1));
        }
        else
        {
            return false;
        }
    }
    bool isMatch(string s, string p)
    {
        return solve(s, p, s.length() - 1, p.length() - 1);
    }
};

int main()
{
    Solution sl;

    string s = "abcde", p = "a*cd?";

    bool check = sl.isMatch(s, p);

    if (check)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}