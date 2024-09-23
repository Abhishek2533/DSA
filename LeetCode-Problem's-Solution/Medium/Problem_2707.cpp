/*

2707. Extra Characters in a String


You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present in any of the substrings.
Return the minimum number of extra characters left over if you break up s optimally.


Example 1:
Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
Output: 1
Explanation: We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. There is only 1 unused character (at index 4), so we return 1.

Example 2:
Input: s = "sayhelloworld", dictionary = ["hello","world"]
Output: 3
Explanation: We can break s in two substrings: "hello" from index 3 to 7 and "world" from index 8 to 12. The characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters. Hence, we return 3.


Constraints:
1 <= s.length <= 50
1 <= dictionary.length <= 50
1 <= dictionary[i].length <= 50
dictionary[i] and s consists of only lowercase English letters
dictionary contains distinct words


*/

// SOURCE CODE

class Solution
{
private:
    unordered_map<string, int> um; // Dictionary words
    unordered_map<int, int> dp;    // Memoization map for storing dp results

    int solve(string &s, int ind)
    {
        // base condition, where recursion gets over
        if (ind >= s.size())
        {
            return 0;
        }

        if (dp.find(ind) != dp.end())
        {
            // Return memoized result if already computed
            return dp[ind];
        }

        int extra = INT_MAX;
        string temp = "";

        // Try all substrings starting from the current index
        for (int i = ind; i < s.size(); i++)
        {
            temp += s[i];
            if (um.find(temp) != um.end())
            {
                // If the substring is in the dictionary, solve for the remaining part
                extra = min(extra, solve(s, i + 1));
            }
        }

        // Consider the case where the current character is counted as extra
        // basically skipping the current ind = 0
        extra = min(extra, 1 + solve(s, ind + 1));

        // Memoize the result for the current index
        dp[ind] = extra;

        return dp[ind];
    }

public:
    int minExtraChar(string s, vector<string> &dictionary)
    {
        for (auto &val : dictionary)
            um[val]++;

        return solve(s, 0);
    }
};