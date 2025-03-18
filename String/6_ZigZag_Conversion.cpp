#include <bits/stdc++.h>
using namespace std;

/*

Zigzag Conversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);


Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"

*/

class Solution
{
public:
    string convert(string s, int numRows)
    {
        vector<string> ans(numRows);
        if (numRows == 1)
        {
            return s;
        }
        bool flag = false;
        int i = 0;
        for (auto ch : s)
        {
            ans[i] = ans[i] + ch;
            if (i == 0 || i == numRows - 1)
            {
                flag = !flag;
            }
            if (flag)
            {
                i = i + 1;
            }
            else
            {
                i = i - 1;
            }
        }
        string zigzag = "";
        for (auto str : ans)
        {
            zigzag = zigzag + str;
        }
        return zigzag;
    }

    void printZigZag(string result, int numRows)
    {
        if (numRows == 1)
        {
            cout << result << endl;
            return;
        }

        int len = result.length();
        int numCols = len;
        vector<vector<char>> matrix(numRows, vector<char>(numCols, ' '));

        int row = 0, col = 0;
        bool goingDown = true;
        for (char c : result)
        {
            matrix[row][col] = c;
            if (goingDown)
            {
                if (row == numRows - 1)
                {
                    goingDown = false;
                    row--;
                    col++;
                }
                else
                {
                    row++;
                }
            }
            else
            {
                if (row == 0)
                {
                    goingDown = true;
                    row++;
                }
                else
                {
                    row--;
                    col++;
                }
            }
        }

        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < numCols; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    string s = "PAYPALISHIRING";
    int numRows = 4;

    Solution sl;

    string result = sl.convert(s, numRows);
    cout << "Result : " << result << endl;

    cout << "Zig Zag Grid :" << endl;

    sl.printZigZag(result, 4);
    return 0;
}