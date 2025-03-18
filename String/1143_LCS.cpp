/*
1143. Longest Common Subsequence

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.



Example 1:

Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
*/

#include <iostream>
#include <cstring>
using namespace std;

class Solution
{
public:
    int t[100][100];
    int solve(string &s1, string &s2, int i, int j)
    {
        if (i >= s1.length() || j >= s2.length())
        {
            return 0;
        }
        if (t[i][j] != -1)
        {
            return t[i][j];
        }
        if (s1[i] == s2[j])
        {
            int temp = solve(s1, s2, i + 1, j + 1);
            t[i][j] = 1 + temp;
        }
        else
        {
            int left = solve(s1, s2, i + 1, j);
            int right = solve(s1, s2, i, j + 1);
            t[i][j] = max(left, right);
        }
        return t[i][j];
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        memset(t, -1, sizeof(t));
        return solve(text1, text2, 0, 0);
    }
};

int main()
{
    Solution sl;
    string text1 = "abcde";
    string text2 = "ace";
    cout << sl.longestCommonSubsequence(text1, text2) << endl;

    return 0;
}
