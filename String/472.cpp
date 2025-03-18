/*
Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words (not necessarily distinct) in the given array.


Example 1:

Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]

Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";
"dogcatsdog" can be concatenated by "dog", "cats" and "dog";
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
Example 2:

Input: words = ["cat","dog","catdog"]
Output: ["catdog"]

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<string, bool> mp;

    bool isConcatenated(string word, unordered_set<string> &st)
    {
        if (mp.find(word) != mp.end())
        {
            return mp[word];
        }
        for (int i = 0; i < word.length(); i++)
        {

            string prefix = word.substr(0, i + 1);
            string suffix = word.substr(i + 1);

            if ((st.find(prefix) != st.end() && isConcatenated(suffix, st)) || (st.find(prefix) != st.end() && st.find(suffix) != st.end()))
            {

                return mp[word] = true;
            }
        }
        return mp[word] = false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        int n = words.size();

        mp.clear();

        unordered_set<string> st(begin(words), end(words));

        vector<string> result;

        for (int i = 0; i < n; i++)
        {
            string word = words[i];

            if (isConcatenated(word, st))
            {
                result.push_back(word);
            }
        }

        return result;
    }
};

int main()
{
    vector<string> words = {"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};

    Solution sl;
    vector<string> result = sl.findAllConcatenatedWordsInADict(words);

    for (string i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}