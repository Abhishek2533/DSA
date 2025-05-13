/*

3335. Total Characters in String After Transformations I


You are given a string s and an integer t, representing the number of transformations to perform. In one transformation, every character in s is replaced according to the following rules:
If the character is 'z', replace it with the string "ab".
Otherwise, replace it with the next character in the alphabet. For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.
Return the length of the resulting string after exactly t transformations.
Since the answer may be very large, return it modulo 109 + 7.


Example 1:
Input: s = "abcyy", t = 2
Output: 7
Explanation:
First Transformation (t = 1):
'a' becomes 'b'
'b' becomes 'c'
'c' becomes 'd'
'y' becomes 'z'
'y' becomes 'z'
String after the first transformation: "bcdzz"
Second Transformation (t = 2):
'b' becomes 'c'
'c' becomes 'd'
'd' becomes 'e'
'z' becomes "ab"
'z' becomes "ab"
String after the second transformation: "cdeabab"
Final Length of the string: The string is "cdeabab", which has 7 characters.

Example 2:
Input: s = "azbk", t = 1
Output: 5
Explanation:
First Transformation (t = 1):
'a' becomes 'b'
'z' becomes "ab"
'b' becomes 'c'
'k' becomes 'l'
String after the first transformation: "babcl"
Final Length of the string: The string is "babcl", which has 5 characters.


Constraints:
1 <= s.length <= 105
s consists only of lowercase English letters.
1 <= t <= 105


*/

// SOURCE CODE





// METHOD 1: TC-> O(t*N) | SC -> O(N);

class Solution
{
public:
    const int MOD = 1e9 + 7;
    int lengthAfterTransformations(string s, int t)
    {
        int n = s.length();
        unordered_map<char, int> mpp;

        for (auto &ch : s)
            mpp[ch]++;

        for (int count = 1; count <= t; count++)
        {
            unordered_map<char, int> temp;
            for (auto &it : mpp)
            {
                if (it.first != 'z')
                    temp[it.first + 1] = (temp[it.first + 1] + it.second) % MOD;
                else
                {
                    temp['a'] = (temp['a'] + it.second) % MOD;
                    temp['b'] = (temp['b'] + it.second) % MOD;
                }
            }

            mpp = move(temp);
        }

        int res = 0;
        for (auto &it : mpp)
            res += it.second;

        return res;
    }
};





// METHOD 2: TC-> O(t + N) | SC -> O(26);

class Solution
{
public:
    const int MOD = 1e9 + 7;
    int lengthAfterTransformations(string s, int t)
    {
        int n = s.length();
        vector<int> mpp(26, 0);

        for (auto &ch : s)
            mpp[ch - 'a']++;

        for (int count = 1; count <= t; count++)
        {
            vector<int> temp(26, 0);
            for (int i = 0; i < 26; i++)
            {
                char ch = i + 'a';
                int freq = mpp[i];

                if (ch != 'z')
                    temp[(ch + 1) - 'a'] = (temp[(ch + 1) - 'a'] + mpp[i]) % MOD;
                else
                {
                    temp['a' - 'a'] = (temp['a' - 'a'] + mpp[i]) % MOD;
                    temp['b' - 'a'] = (temp['b' - 'a'] + mpp[i]) % MOD;
                }
            }

            mpp = move(temp);
        }

        int res = 0;
        for (int i = 0; i < 26; i++)
            res = (res + mpp[i]) % MOD;

        return res;
    }
};