/*

Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

For example, swapping at indices 0 and 2 in "abcd" results in "cbad".


Example 1:

Input: s = "ab", goal = "ba"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.
Example 2:

Input: s = "ab", goal = "ab"
Output: false
Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.
Example 3:

Input: s = "aa", goal = "aa"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool checkFreq(string s)
    {
        int a[26] = {0};
        for (char &ch : s)
        {
            a[ch - 'a']++;

            if (a[ch - 'a'] > 1)
            {
                return true;
            }
        }
        return false;
    }
    bool buddyStrings(string s, string goal)
    {
        if (s.length() != goal.length())
        {
            return false;
        }

        if (s == goal)
        {
            return checkFreq(s);
        }

        vector<int> index;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != goal[i])
            {
                index.push_back(i);
            }
        }

        if (index.size() != 2)
        {
            return false;
        }

        swap(s[index[0]], s[index[1]]);
        return s == goal;
    }
};

int main()
{
    string s = "ab";
    string goal = "ba";

    Solution sl;

    bool check = sl.buddyStrings(s, goal);

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