/*
Find the Index of the First Occurrence in a String

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.



Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1
*/

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.length();
        int n = needle.length();

        for (int i = 0; i < m - n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    break;
                }
                if (j == n - 1)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};

int main()
{
    string haystack = "sadbutsad";
    string needle = "sad";

    Solution sl;

    int result = sl.strStr(haystack, needle);

    cout << result << endl;

    return 0;
}