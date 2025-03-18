/*
A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.



Example 1:

Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]

Example 2:

Input: s = "0000"
Output: ["0.0.0.0"]

Example 3:

Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;
    vector<string> result;

    bool isValid(string curr)
    {
        if (curr[0] == '0')
            return false;

        int val = stoi(curr);
        return val <= 255;
    }

    void solve(string &s, int idx, int parts, string curr)
    {
        if (idx == n && parts == 4)
        {
            result.push_back(curr.substr(0, curr.length() - 1));
            return;
        }

        if (idx + 1 <= n)
        {

            solve(s, idx + 1, parts + 1, curr + s.substr(idx, 1) + ".");
        }

        if (idx + 2 <= n && isValid(s.substr(idx, 2)))
        {

            solve(s, idx + 2, parts + 1, curr + s.substr(idx, 2) + ".");
        }

        if (idx + 3 <= n && isValid(s.substr(idx, 3)))
        {
            solve(s, idx + 3, parts + 1, curr + s.substr(idx, 3) + ".");
        }
    }

    vector<string> restoreIpAddresses(string s)
    {
        n = s.length();
        if (n > 12)
        {
            return {};
        }
        int parts = 0;
        string cur = "";

        solve(s, 0, parts, cur);
        return result;
    }
};

int main()
{
    Solution sl;

    string my_str = "25525511135";

    vector<string> result = sl.restoreIpAddresses(my_str);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}