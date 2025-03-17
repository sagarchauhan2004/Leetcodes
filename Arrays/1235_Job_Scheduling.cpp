/*
1235. Maximum Profit in Job Scheduling

We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

Example 1:

Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job.
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
Example 2:

Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job.
Profit obtained 150 = 20 + 70 + 60.
Example 3:

Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6

Constraints:

1 <= startTime.length == endTime.length == profit.length <= 5 * 104
1 <= startTime[i] < endTime[i] <= 109
1 <= profit[i] <= 104
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Clasic_Recursion
{
public:
    int n;
    int getNextIndex(vector<vector<int>> &nums, int i, int target)
    {
        int start = i;
        int end = n - 1;

        int result = n + 1;

        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (nums[mid][0] >= target)
            {
                result = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return result;
    }
    int solve(vector<vector<int>> &nums, int i)
    {
        if (i >= n)
        {
            return 0;
        }
        int next = getNextIndex(nums, i + 1, nums[i][1]);
        int Taken = nums[i][2] + solve(nums, next);
        int notTaken = solve(nums, i + 1);
        return max(Taken, notTaken);
    }
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        n = startTime.size();

        vector<vector<int>> nums(n, vector<int>(3, 0));

        for (int i = 0; i < n; i++)
        {
            nums[i][0] = startTime[i];
            nums[i][1] = endTime[i];
            nums[i][2] = profit[i];
        }

        sort(begin(nums), end(nums));

        return solve(nums, 0);
    }
};

int main()
{
    Clasic_Recursion cr;
    vector<int> startTime = {1, 2, 3, 4, 6};
    vector<int> endTime = {3, 5, 10, 6, 9};
    vector<int> profit = {20, 20, 100, 70, 60};

    cout << "Maximum profit using clasic Recursion : " << cr.jobScheduling(startTime, endTime, profit);
    return 0;
}