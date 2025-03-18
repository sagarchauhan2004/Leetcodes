/*

5. Longest Palindromic Substring

Given a string s, return the longest
palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"

Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"

*/

#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

class Solution {
public:
    int t[10][10];

    bool solve(string& s, int i, int j) {
        if (i >= j) {
            return true;
        }
        if (t[i][j] != -1) {
            return t[i][j];
        }
        if (s[i] == s[j]) {
            return t[i][j] = solve(s, i + 1, j - 1);
        }
        return t[i][j] = false;
    }

    string longestPalindrome(string s) {
        
        int n = s.length();

        memset(t, -1, sizeof(t));

        int maxLen = INT_MIN;

        int start_point = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(s, i, j)) {
                    if(j - i + 1 > maxLen){
                        maxLen = j - i + 1;
                        start_point = i;
                    }
                }
            }
        }
        return s.substr(start_point, maxLen);
    }
};
int main()
{
    string s = "babad";

    Solution sl;

    string ans = sl.longestPalindrome(s);

    cout << ans << endl;
    return 0;
}