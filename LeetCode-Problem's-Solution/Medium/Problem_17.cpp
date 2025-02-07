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



// SOURCE CODE

// METHOD - 1

class Solution
{
private:
    void solve(string digits, string output, int index, vector<string> &ans, string mapping[])
    {
        // base condition
        if (index >= digits.length())
        {
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0';
        string value = mapping[number];

        for (int i = 0; i < value.length(); i++)
        {
            output.push_back(value[i]);
            solve(digits, output, index + 1, ans, mapping);
            output.pop_back();
        }
    };

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;

        if (digits.length() == 0)
            return ans;

        string output;
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(digits, output, index, ans, mapping);
        return ans;
    }
};



// METHOD - 2

class Solution {
public:
    void solve(string& digits, vector<string>& ans, int ind, string temp, unordered_map<char, string>& mpp) {
        if(ind == digits.size()) return ans.push_back(temp);

        for(char c : mpp.at(digits[ind])) solve(digits, ans, ind+1, temp+c, mpp);
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if(digits.empty()) return ans;
        
        unordered_map<char, string> mpp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        solve(digits, ans, 0, "", mpp);
        return ans;
    }
};