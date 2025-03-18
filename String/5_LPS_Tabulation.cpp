#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool solve(string &s, int i, int j, vector<vector<bool>> &dp)
    {
        if (i >= j)
        {
            return true;
        }
        return dp[i][j];
    }

    string longestPalindrome(string s)
    {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int max_len = 1;
        int start_point = 0;

        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }

        // Check for sub-string of length 2.
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                start_point = i;
                max_len = 2;
            }
        }

        // Check for lengths greater than 2.
        for (int len = 3; len <= n; len++)
        {
            for (int i = 0; i < n - len + 1; i++)
            {
                int j = i + len - 1; // Ending index of substring

                // Update DP table and use solve function to check if s[i..j] is a palindrome
                if (s[i] == s[j] && solve(s, i + 1, j - 1, dp))
                {
                    dp[i][j] = true;

                    if (len > max_len)
                    {
                        start_point = i;
                        max_len = len;
                    }
                }
            }
        }

        // Return the longest palindromic substring
        return s.substr(start_point, max_len);
    }
};

int main()
{
    Solution sol;
    string s = "babad";
    cout << "Longest Palindromic Substring: " << sol.longestPalindrome(s) << endl;
    return 0;
}
