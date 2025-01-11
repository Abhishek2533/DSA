/*

Problem Statement

Developers often struggle naming variables. Companies like JetBrains and Microsoft use smart naming suggestions in their IDEs to improve code readability. You're building a smart code editor that helps developers choose variable names. The editor suggests palindromic variable names (like "level" or "radar") as they're easy to remember. Your feature should detect if a string can become a palindrome by removing just one character.


Input Format

A single string (s) (length: (|s|  <= 10^5)).
    The string contains only lowercase letters ('a' to 'z').


Output Format

Return true if the string can become a palindrome by removing at most one character, otherwise return false.


Example

Input:
raceecar

    
Output: 
true


Example 2

Input:
abccba

    
Output: 
true



Constraints:
1. (1 <= |s| length of s<= 10^5)
2. The input string (s) contains only lowercase alphabets.
3. Strings are guaranteed to have a minimum length of 1.


*/


// SOURCE CODE


#include <iostream>
#include <string>
using namespace std;


bool isPalindrome(const string& s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}


// you need to implement this function only
bool canBePalindrome(string s) {
    // your code here
    int l = 0;
    int r = s.length() - 1;
        
    while (l < r) {
        if (s[l] != s[r]) {
            return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
        }
        l++;
        r--;
    }
    return true;
}

int main() {
    string s;
    cin >> s; 
    // please don't modify the main function
    cout << (canBePalindrome(s) ? "YES" : "NO");
    return 0;
}