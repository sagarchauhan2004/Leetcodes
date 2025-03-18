/*

Longest Substring Without Repeating Characters

Given a string s, find the length of the longest
substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxlen = 0;
        unordered_set<char> charSet;

        for (int i = 0; i < s.size(); i++)
        {
            int j = i;
            while (j < s.size() && charSet.find(s[j]) == charSet.end())
            {
                charSet.insert(s[j]);
                j++;
            }
            maxlen = max(maxlen, j - i);
            charSet.clear();
        }
        return maxlen;
    }
};

int main()
{
    Solution sl;

    string s = "abcabcbb";

    int ans = sl.lengthOfLongestSubstring(s);

    cout << ans << endl;

    return 0;
}