/*

214. Shortest Palindrome


You are given a string s. You can convert s to a palindrome by adding characters in front of it.
Return the shortest palindrome you can find by performing this transformation.


Example 1:
Input: s = "aacecaaa"
Output: "aaacecaaa"

Example 2:
Input: s = "abcd"
Output: "dcbabcd"


Constraints:
0 <= s.length <= 5 * 104
s consists of lowercase English letters only.


*/

// SOURCE CODE

class Solution
{
private:
    int kmpAlgo(const string &txt, const string &patt)
    {
        string newString = patt + '#' + txt;
        vector<int> prefixArr(newString.length(), 0);
        int i = 1, k = 0;
        while (i < newString.length())
        {
            if (newString[i] == newString[k])
            {
                k++;
                prefixArr[i] = k;
                i++;
            }
            else
            {
                if (k > 0)
                {
                    k = prefixArr[k - 1];
                }
                else
                {
                    prefixArr[i] = 0;
                    i++;
                }
            }
        }
        return prefixArr.back();
    }

public:
    string shortestPalindrome(string s)
    {
        int count = kmpAlgo(string(s.rbegin(), s.rend()), s);
        return string(s.rbegin(), s.rend()).substr(0, s.length() - count) + s;
    }
};