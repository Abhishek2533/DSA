/*

1662. Check If Two String Arrays are Equivalent

Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.
A string is represented by an array if the array elements concatenated in order forms the string.


Example 1:
Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.

Example 2:
Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
Output: false

Example 3:
Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
Output: true
 

Constraints:
1 <= word1.length, word2.length <= 103
1 <= word1[i].length, word2[i].length <= 103
1 <= sum(word1[i].length), sum(word2[i].length) <= 103
word1[i] and word2[i] consist of lowercase letters.


*/

// SOURCE CODE


class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "", s2= "";
        for(string s : word1) s1+=s;
        for(string s : word2) s2+=s;

        return s1==s2;
    }
};






// METHOD-2

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int str1=0, str2=0, index1=0, index2=0;

        while(str1 < word1.size() && str2<word2.size()) {
            char ch1 = word1[str1][index1];
            char ch2 = word2[str2][index2];

            if(ch1 != ch2) return false;
            
            index1++, index2++;

            if(index1 == word1[str1].size()) {
                index1=0;
                str1++;
            }

            if(index2 == word2[str2].size()) {
                index2=0;
                str2++;
            }
        }

        return str1 == word1.size() && str2 == word2.size();
    }
};