/*
You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.

Return a list answer of size 2 where:

answer[0] is a list of all players that have not lost any matches.
answer[1] is a list of all players that have lost exactly one match.
The values in the two lists should be returned in increasing order.

Note:

You should only consider the players that have played at least one match.
The testcases will be generated such that no two matches will have the same outcome.


Example 1:

Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]

Output: [[1,2,10],[4,5,7,8]]

Explanation:
Players 1, 2, and 10 have not lost any matches.
Players 4, 5, 7, and 8 each have lost one match.
Players 3, 6, and 9 each have lost two matches.
Thus, answer[0] = [1,2,10] and answer[1] = [4,5,7,8].

Example 2:

Input: matches = [[2,3],[1,3],[5,4],[6,4]]

Output: [[1,2,5,6],[]]

Explanation:
Players 1, 2, 5, and 6 have not lost any matches.
Players 3 and 4 each have lost two matches.
Thus, answer[0] = [1,2,5,6] and answer[1] = [].

*/

#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        unordered_map<int, int> lost_map;

        for (int i = 0; i < matches.size(); i++)
        {
            int loser = matches[i][1];

            lost_map[loser]++;
        }

        vector<int> notLost;
        vector<int> LostOnce;

        for (int i = 0; i < matches.size(); i++)
        {
            int winner = matches[i][0];
            int loser = matches[i][1];

            if (lost_map.find(winner) == lost_map.end())
            {
                notLost.push_back(winner);
                lost_map[winner] = 2;
            }
            if (lost_map[loser] == 1)
            {
                LostOnce.push_back(loser);
            }
        }

        sort(LostOnce.begin(), LostOnce.end());
        sort(notLost.begin(), notLost.end());
        return {notLost, LostOnce};
    }
};

int main()
{
    Solution sl;

    vector<vector<int>> matches = {{1, 3}, {2, 3}, {3, 6}, {5, 6}, {5, 7}, {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}};

    vector<vector<int>> result = sl.findWinners(matches);

    for (auto &i : result)
    {
        for (auto &j : i)
        {
            cout << j << " ";
        }
    }

    return 0;
}