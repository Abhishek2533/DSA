/*

242. Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false


Constraints:
1 <= s.length, t.length <= 5 * 10^4
s and t consist of lowercase English letters.


Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

*/

// SOURCE CODE

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// ANOTHER METHOD

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> count;

        for (auto x : s)
        {
            count[x]++;
        }
        for (auto x : t)
        {
            count[x]--;
        }
        for (auto x : count)
        {
            if (x.second != 0)
                return false;
        }

        return true;
    }
};