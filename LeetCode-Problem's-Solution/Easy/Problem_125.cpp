/*

125. Valid Palindrome


A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.


Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
    Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
    Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
    Explanation: s is an empty string "" after removing non-alphanumeric characters.
    Since an empty string reads the same forward and backward, it is a palindrome.

*/

// SOURCE CODE

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string result;
        for (char c : s)
        {
            if (isalnum(c))
            {
                result += tolower(c);
            }
        }
        return isPalindromeHelper(result, 0);
    }

private:
    bool isPalindromeHelper(string &s, int i)
    {
        int n = s.length();
        if (i >= n / 2)
            return true;
        if (s[i] != s[n - i - 1])
            return false;
        return isPalindromeHelper(s, i + 1);
    }
};