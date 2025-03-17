/*
904. Fruit Into Baskets

You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.



Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
Example 2:

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
Example 3:

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].


Constraints:

1 <= fruits.length <= 105
0 <= fruits[i] < fruits.length
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int Brute_Force(vector<int> v)
    {
        int n = v.size(), max_len = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> st;

            for (int j = i; j < n; j++)
            {
                st.insert(v[j]);
                if (st.size() <= 2)
                {
                    max_len = max(max_len, j - i + 1);
                }
                else
                {
                    break;
                }
            }
        }
        return max_len;
    }
    int totalFruit(vector<int> &fruits)
    {
        int max_len = 0, n = fruits.size(), l = 0, r = 0;
        unordered_map<int, int> mp;
        while (r < n)
        {
            mp[fruits[r]]++;

            if (mp.size() > 2)
            {
                while (mp.size() > 2)
                {
                    mp[fruits[l]]--;
                    if (mp[fruits[l]] == 0)
                        mp.erase(fruits[l]);
                    l++;
                }
            }
            if (mp.size() <= 2)
            {
                max_len = max(max_len, r - l + 1);
            }
            r++;
        }
        return max_len;
    }
};

int main()
{
    Solution sl;

    vector<int> v = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};

    cout << "Brute Force Approach : " << sl.Brute_Force(v) << endl;
    cout << "Optimal Approach : " << sl.totalFruit(v) << endl;

    v = {1, 2, 3, 2, 2};

    cout << "Brute Force Approach : " << sl.Brute_Force(v) << endl;
    cout << "Optimal Approach : " << sl.totalFruit(v) << endl;

    return 0;
}