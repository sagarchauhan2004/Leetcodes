/*
2948. Make Lexicographically Smallest Array by Swapping Elements

You are given a 0-indexed array of positive integers nums and a positive integer limit.

In one operation, you can choose any two indices i and j and swap nums[i] and nums[j] if |nums[i] - nums[j]| <= limit.

Return the lexicographically smallest array that can be obtained by performing the operation any number of times.

An array a is lexicographically smaller than an array b if in the first position where a and b differ, array a has an element that is less than the corresponding element in b. For example, the array [2,10,3] is lexicographically smaller than the array [10,2,3] because they differ at index 0 and 2 < 10.



Example 1:

Input: nums = [1,5,3,9,8], limit = 2
Output: [1,3,5,8,9]
Explanation: Apply the operation 2 times:
- Swap nums[1] with nums[2]. The array becomes [1,3,5,9,8]
- Swap nums[3] with nums[4]. The array becomes [1,3,5,8,9]
We cannot obtain a lexicographically smaller array by applying any more operations.
Note that it may be possible to get the same result by doing different operations.
Example 2:

Input: nums = [1,7,6,18,2,1], limit = 3
Output: [1,6,7,18,1,2]
Explanation: Apply the operation 3 times:
- Swap nums[1] with nums[2]. The array becomes [1,6,7,18,2,1]
- Swap nums[0] with nums[4]. The array becomes [2,6,7,18,1,1]
- Swap nums[0] with nums[5]. The array becomes [1,6,7,18,1,2]
We cannot obtain a lexicographically smaller array by applying any more operations.
Example 3:

Input: nums = [1,7,28,19,10], limit = 3
Output: [1,7,28,19,10]
Explanation: [1,7,28,19,10] is the lexicographically smallest array we can obtain because we cannot apply the operation on any two indices.

Example 4 : [1,81,10,79,36,2,87,12,20,77] , limit = 7
Output : [1,77,10,79,36,2,81,12,20,87]

Example 5 = [5,100,44,45,16,30,14,65,83,64] , limit = 15
Output : [5,100,14,16,30,44,45,64,83,65]


Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= limit <= 109
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {
        int n = nums.size();

        vector<int> v = nums;

        sort(begin(v), end(v));

        int groupNum = 0;

        unordered_map<int, int> numToGroup;

        numToGroup[v[0]] = groupNum;

        unordered_map<int, list<int>> groupList;
        groupList[groupNum].push_back(v[0]);

        for (int i = 1; i < n; i++)
        {
            if (abs(v[i] - v[i - 1]) > limit)
            {
                groupNum++;
            }
            numToGroup[v[i]] = groupNum;
            groupList[groupNum].push_back(v[i]);
        }

        vector<int> result(n);

        for (int i = 0; i < n; i++)
        {
            int num = nums[i];

            int group = numToGroup[num];

            result[i] = *(groupList[group].begin());
            groupList[group].pop_front();
        }
        return result;
    }
};

int main()
{
    Solution sl;

    vector<int> nums = {10, 2, 7, 3, 8, 4, 9, 6, 3};
    int limit = 1;

    vector<int> ans = sl.lexicographicallySmallestArray(nums, limit);

    for (int val : ans)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}