/*

53. Maximum Subarray

Given an integer array nums, find the
subarray
with the largest sum, and return its sum.

 
Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    // BruteForce
    int maxSubArray1(vector<int> &nums)
    {
        int n = nums.size();

        int maxSum = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int currSum = 0;
            for (int j = i; j < n; j++)
            {
                currSum += nums[j];
                maxSum = max(maxSum, currSum);
            }
        }
        return maxSum;
    }
    // Using Kadane's Algorithm
    int maxSubArray2(vector<int> &nums)
    {
        int currSum = 0;
        int maxSum = INT_MIN;

        for (int val : nums)
        {
            currSum += val;
            maxSum = max(maxSum, currSum);
            if (currSum < 0)
            {
                currSum = 0;
            }
        }
        return maxSum;
    }
};

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution sl;

    int ans = sl.maxSubArray2(nums);
    cout << ans << endl;

    return 0;
}