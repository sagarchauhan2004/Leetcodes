/*
3283. Maximum Number of Moves to Kill All Pawns

There is a 50 x 50 chessboard with one knight and some pawns on it. You are given two integers kx and ky where (kx, ky) denotes the position of the knight, and a 2D array positions where positions[i] = [xi, yi] denotes the position of the pawns on the chessboard.

Alice and Bob play a turn-based game, where Alice goes first. In each player's turn:

The player selects a pawn that still exists on the board and captures it with the knight in the fewest possible moves. Note that the player can select any pawn, it might not be one that can be captured in the least number of moves.

In the process of capturing the selected pawn, the knight may pass other pawns without capturing them. Only the selected pawn can be captured in this turn.

Alice is trying to maximize the sum of the number of moves made by both players until there are no more pawns on the board, whereas Bob tries to minimize them.

Return the maximum total number of moves made during the game that Alice can achieve, assuming both players play optimally.

Note that in one move, a chess knight has eight possible positions it can move to, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.


Example 1:

Input: kx = 1, ky = 1, positions = [[0,0]]

Output: 4

Explanation:

The knight takes 4 moves to reach the pawn at (0, 0).

Example 2:

Input: kx = 0, ky = 2, positions = [[1,1],[2,2],[3,3]]

Output: 8

Explanation:

Alice picks the pawn at (2, 2) and captures it in two moves: (0, 2) -> (1, 4) -> (2, 2).
Bob picks the pawn at (3, 3) and captures it in two moves: (2, 2) -> (4, 1) -> (3, 3).
Alice picks the pawn at (1, 1) and captures it in four moves: (3, 3) -> (4, 1) -> (2, 2) -> (0, 3) -> (1, 1).

Approach (BFS + DP with mask : Game Strategy)
// T.C : O(n + n*2^n) //BFS - called n times. Note that it works in a chess board of fixed size and hence takes O(1) time. , solve functions visits n*2^n states in dp
// S.C : O(n*2^n) //space taken by dp array
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring> // for memset
using namespace std;

class Solution
{
public:
    vector<vector<int>> directions = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    void BFS(int x, int y, int index, vector<vector<int>> &minDist, vector<vector<int>> &pos)
    {
        vector<vector<int>> t(50, vector<int>(50, -1));
        queue<pair<int, int>> que;
        que.push({x, y});
        t[x][y] = 0;

        while (!que.empty())
        {
            pair<int, int> curr = que.front();
            que.pop();

            int currX = curr.first;
            int currY = curr.second;

            for (auto &dir : directions)
            {
                int newX = currX + dir[0];
                int newY = currY + dir[1];

                if (newX >= 0 && newX < 50 && newY >= 0 && newY < 50 && t[newX][newY] == -1)
                {
                    t[newX][newY] = t[currX][currY] + 1;
                    que.push({newX, newY});
                }
            }
        }

        for (int i = 0; i < pos.size(); i++)
        {
            int x_ = pos[i][0];
            int y_ = pos[i][1];

            minDist[index][i] = t[x_][y_];
        }
    }

    int solve(vector<vector<int>> &minDist, int idx, int mask, int n, bool Alice, int dp[51][1 << 15])
    {
        if (mask == 0)
        {
            return 0; // no more moves/steps required
        }

        if (dp[idx][mask] != -1)
        {
            return dp[idx][mask];
        }

        int result = (Alice == true) ? -1 : 1e9;

        for (int i = 1; i < n; i++)
        {
            if (mask & (1 << (i - 1)))
            {
                int moves = minDist[idx][i];

                if (Alice == true)
                {
                    result = max(result, moves + solve(minDist, i, mask ^ (1 << (i - 1)), n, !Alice, dp));
                }
                else
                {
                    result = min(result, moves + solve(minDist, i, mask ^ (1 << (i - 1)), n, !Alice, dp));
                }
            }
        }

        return dp[idx][mask] = result;
    }

    int maxMoves(int kx, int ky, vector<vector<int>> &positions)
    {
        int n = positions.size();

        vector<vector<int>> pos;
        pos.push_back({kx, ky});
        for (auto &vec : positions)
        {
            pos.push_back({vec[0], vec[1]});
        }

        // minDist[][]
        vector<vector<int>> minDist(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < pos.size(); i++)
        {
            int x = pos[i][0];
            int y = pos[i][1];
            BFS(x, y, i, minDist, pos);
        }

        // call solve
        // 0th index par knight hai mera in pos array
        bool Alice = true;
        int dp[51][1 << 15];
        memset(dp, -1, sizeof(dp));
        return solve(minDist, 0, (1 << n) - 1, pos.size(), Alice, dp);
    }
};

int main()
{
    Solution sl;
    int kx = 0, ky = 2;
    vector<vector<int>> positions = {{1, 1}, {2, 2}, {3, 3}};

    cout << "Maximum total number of moves : " << sl.maxMoves(kx, ky, positions) << endl;

    return 0;
}
