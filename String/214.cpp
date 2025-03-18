/*
You are given a string s. You can convert s to a
palindrome
by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.



Example 1:

Input: s = "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: s = "abcd"
Output: "dcbabcd"
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

class Solution
{
public:
    // Memory Limit Exceeded
    string shortestPalindrome1(string s)
    {
        string rev = s;

        reverse(rev.begin(), rev.end());

        for (int i = 0; i < s.length(); i++)
        {
            if (s.substr(0, s.length() - i) == rev.substr(i))
            {
                return rev.substr(0, i) + s;
            }
        }
        return rev + s;
    }

    string shortestPalindrome(string s)
    {
        string rev = s;

        reverse(rev.begin(), rev.end());

        for (int i = 0; i < s.length(); i++)
        {
            if (!memcmp(s.c_str(), rev.c_str() + i, s.length() - i))
            {
                return rev.substr(0, i) + s;
            }
        }
        return rev + s;
    }
};

int main()
{
    string s = "abac";

    Solution sl;

    string result = sl.shortestPalindrome1(s);
    cout << result << endl;
    return 0;
}