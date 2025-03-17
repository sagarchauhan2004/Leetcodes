/*
1861. Rotating the Box

You are given an m x n matrix of characters box representing a side-view of a box. Each cell of the box is one of the following:

A stone '#'
A stationary obstacle '*'
Empty '.'
The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.

It is guaranteed that each stone in box rests on an obstacle, another stone, or the bottom of the box.

Return an n x m matrix representing the box after the rotation described above.


Example 1:

Input: box = [["#",".","#"]]
Output: [["."],
         ["#"],
         ["#"]]
Example 2:

Input: box = [["#",".","*","."],
              ["#","#","*","."]]
Output: [["#","."],
        ["#","#"],
        ["*","*"],
        [".","."]]
Example 3:

Input: box = [["#","#","*",".","*","."],
              ["#","#","#","*",".","."],
              ["#","#","#",".","#","."]]

Output: [[".","#","#"],
         [".","#","#"],
         ["#","#","*"],
         ["#","*","."],
         ["#",".","*"],
         ["#",".","."]]


Constraints:

m == box.length
n == box[i].length
1 <= m, n <= 500
box[i][j] is either '#', '*', or '.'.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int m = box.size();
        int n = box[0].size();

        vector<vector<char>> result(n, vector<char>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                result[i][j] = box[j][i];
            }
        }

        for (vector<char> &it : result)
        {
            reverse(it.begin(), it.end());
        }

        for (int j = 0; j < m; j++)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                if (result[i][j] == '.')
                {
                    int stoneRow = -1;
                    for (int k = i - 1; k >= 0; k--)
                    {
                        if (result[k][j] == '*')
                        {
                            break;
                        }
                        else if (result[k][j] == '#')
                        {
                            stoneRow = k;
                            break;
                        }
                    }
                    if (stoneRow != -1)
                    {
                        result[i][j] = '#';
                        result[stoneRow][j] = '.';
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution sl;
    vector<vector<char>> box = {{'#', '#', '*', '.', '*', '.'}, {'#', '#', '#', '*', '.', '.'}, {'#', '#', '#', '.', '#', '.'}};
    cout << "Before Rotation : " << endl;
    for (vector<char> &it : box)
    {
        for (char &ch : it)
        {
            cout << ch << " ";
        }
        cout << endl;
    }

    vector<vector<char>> result = sl.rotateTheBox(box);

    cout << "After Rotation : " << endl;

    for (vector<char> &it : result)
    {
        for (char &ch : it)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
    return 0;
}
