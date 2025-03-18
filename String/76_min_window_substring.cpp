/*
76. Minimum Window Substring

Given two strings s and t of lengths m and n respectively, return the minimum window
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.



Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.


Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.


Follow up: Could you find an algorithm that runs in O(m + n) time?
*/

#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.length(), m = t.length(), r = 0, l = 0, start_i = 0,
            min_win = INT_MAX, count = m;

        unordered_map<char, int> mp;

        for (char &ch : t)
        {
            mp[ch]++;
        }

        while (r < n)
        {
            char ch = s[r];

            if (mp[ch] > 0)
            {
                count--;
            }
            mp[ch]--;
            while (count == 0)
            {
                if (r - l + 1 < min_win)
                {
                    min_win = r - l + 1;
                    start_i = l;
                }
                mp[s[l]]++;

                if (mp[s[l]] > 0)
                {
                    count++;
                }
                l++;
            }
            r++;
        }
        return min_win == INT_MAX ? "" : s.substr(start_i, min_win);
    }
};

int main()
{
    Solution sl;
    string s = "ADOBECODEBANC", t = "ABC";
    cout << sl.minWindow(s, t);
    return 0;
}