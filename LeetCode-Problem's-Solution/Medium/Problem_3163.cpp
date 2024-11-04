/*

3163. String Compression III


Given a string word, compress it using the following algorithm:
Begin with an empty string comp. While word is not empty, use the following operation:
Remove a maximum length prefix of word made of a single character c repeating at most 9 times.
Append the length of the prefix followed by c to comp.
Return the string comp.


Example 1:
Input: word = "abcde"
Output: "1a1b1c1d1e"
Explanation:
Initially, comp = "". Apply the operation 5 times, choosing "a", "b", "c", "d", and "e" as the prefix in each operation.
For each prefix, append "1" followed by the character to comp.

Example 2:
Input: word = "aaaaaaaaaaaaaabb"
Output: "9a5a2b"
Explanation:
Initially, comp = "". Apply the operation 3 times, choosing "aaaaaaaaa", "aaaaa", and "bb" as the prefix in each operation.
For prefix "aaaaaaaaa", append "9" followed by "a" to comp.
For prefix "aaaaa", append "5" followed by "a" to comp.
For prefix "bb", append "2" followed by "b" to comp.


Constraints:
1 <= word.length <= 2 * 105
word consists only of lowercase English letters.

*/

// SOURCE CODE





// BRUTE FORCE - TLE

class Solution {
public:
    string compressedString(string word) {
        string comp="";
        int i=0;
        while(i<word.size()) {
            int j=i;
            int count=1;
            
            while(j<word.size() && word[i] == word[j] && count<=9) {
                count++;
                j++;
            }

            if(count==9) {
                comp += to_string(count) + word[i];
            } else {
                int len = j-i;
                comp += to_string(len) + word[i];
                i=j;
            }
        }

        return comp;
    }
};





// OPTIMIZE
class Solution {
public:
    string compressedString(string word) {
        string comp="";
        int i=0;

        while(i<word.size()) {
            char ch = word[i];
            int count=0;
            
            while(i<word.size() && word[i] == ch && count<9) {
                i++;
                count++;
            }

            comp += to_string(count) + ch;
        }

        return comp;
    }
};