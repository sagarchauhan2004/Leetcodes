/*
You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.



Example 1:

Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
Example 2:

Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isVowel(char ch)
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            return true;
        }
        return false;
    }
    bool halvesAreAlike(string s)
    {
        int n = s.length();

        int i = 0;
        int j = n / 2;

        int countLeft = 0;
        int countRight = 0;

        while (i < n / 2 && j < n)
        {
            if (isVowel(s[i]))
            {
                countLeft++;
            }
            if (isVowel(s[j]))
            {
                countRight++;
            }
            i++;
            j++;
        }

        return countLeft == countRight;
    }
};

int main()
{
    Solution sl;

    string s = "book";

    bool check = sl.halvesAreAlike(s);

    if (check)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}