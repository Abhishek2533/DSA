/*

131. Palindrome Partitioning


Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.


Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:
Input: s = "a"
Output: [["a"]]


Constraints:
1 <= s.length <= 16
s contains only lowercase English letters.


*/

// SOURCE CODE

class Solution {
public:
    bool isPalindrome(string s, int start, int end) {
        while(start<=end) if(s[start++] != s[end--]) return false;
        return true;
    }
    void solve(string& s, int ind, vector<string>& temp, vector<vector<string>>& ans) {
        if(ind==s.size()) return ans.push_back(temp);

        for(int i=ind; i<s.size(); i++) {
            if(isPalindrome(s, ind, i)) {
                temp.push_back(s.substr(ind, i-ind+1));
                solve(s, i+1, temp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s, 0, temp, ans);
        return ans;
    }
};