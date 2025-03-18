/*
17. Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.




Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]


Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    void solve(int idx, string &digits, string &temp,
               unordered_map<char, string> &mp, vector<string> &result)
    {
        if (idx >= digits.length())
        {
            result.push_back(temp);
            return;
        }
        char ch = digits[idx];
        string str = mp[ch];

        for (int i = 0; i < str.length(); i++)
        {

            temp.push_back(str[i]);
            solve(idx + 1, digits, temp, mp, result);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0)
        {
            return {};
        }

        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        string temp = "";

        vector<string> result;

        solve(0, digits, temp, mp, result);
        return result;
    }
};

int main()
{
    Solution sl;

    string str1 = "23";
    string str2 = "32";
    string str3 = "45";

    vector<string> result1 = sl.letterCombinations(str1);
    for (string i : result1)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<string> result2 = sl.letterCombinations(str2);
    for (string i : result2)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<string> result3 = sl.letterCombinations(str3);
    for (string i : result3)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}