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

class Solution {
private:
    bool valid(char ch) {
        if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') ) {
            return 1;
        }
        return 0;
    }
    char toLowerCase(char s) {
    if (s >= 'A' && s <= 'Z')
    {
        return s - 'A' + 'a';
    }
    return s;
    }

    bool checkPalindrome(string a) {
        int start = 0;
        int end = a.length() - 1;

        while (start <= end) {
                if (a[start] != a[end]) {
                    return 0;
                }
                else {
                    start++;
                    end--;
                }
            }
        return 1;
    }
public:
    bool isPalindrome(string s) {

        // removing unnecessary
        string temp = "";

        for(int j = 0; j<s.length(); j++) {
            if(valid( s[j] )) {
                temp.push_back(s[j]);
            }
        }

        // convert to lowercase
        for(int j = 0; j<temp.length(); j++) {
                temp[j] = toLowerCase(temp[j]);
        }
        // check palindrome
        return checkPalindrome(temp);
    }
};