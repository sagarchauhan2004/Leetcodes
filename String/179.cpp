/*
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.



Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool custom_comparator(string a, string b)
    {
        if (a + b > b + a)
            return true;
        return false;
    }
    string largestNumber(vector<int> &nums)
    {
        int n = nums.size();

        string result = "";

        vector<string> elements(n);
        for (int i : nums)
        {
            elements.push_back(to_string(i));
        }

        sort(elements.begin(), elements.end(), custom_comparator);

        for (string i : elements)
        {
            result.append(i);
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {3, 30, 34, 5, 9};

    Solution sl;

    string result = sl.largestNumber(nums);

    cout << result << endl;

    return 0;
}