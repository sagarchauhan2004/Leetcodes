#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int solve(string &s1, string &s2, int i, int j)
    {
        if (i >= s1.length() || j >= s2.length())
        {
            return 0;
        }
        if (s1[i] == s2[j])
        {
            int subsequent = solve(s1, s2, i + 1, j + 1);
            int currLCS = 1 + subsequent;
            return currLCS;
        }
        else
        {
            int leftSubsequence = solve(s1, s2, i + 1, j);
            int rightSubsequence = solve(s1, s2, i, j + 1);
            return max(leftSubsequence, rightSubsequence);
        }
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        return solve(text1, text2, 0, 0);
    }
};

int main()
{
    Solution solutionObject;
    string text1 = "mhunuzqrkzsnidwbun";
    string text2 = "szulspmhwpazoxijwbq";
    int result = solutionObject.longestCommonSubsequence(text1, text2);
    cout << result << endl; // Expected output: 3

    return 0;
}
