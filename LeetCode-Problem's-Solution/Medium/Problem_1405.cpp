/*

1405. Longest Happy String


A string s is called happy if it satisfies the following conditions:
s only contains the letters 'a', 'b', and 'c'.
s does not contain any of "aaa", "bbb", or "ccc" as a substring.
s contains at most a occurrences of the letter 'a'.
s contains at most b occurrences of the letter 'b'.
s contains at most c occurrences of the letter 'c'.
Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".
A substring is a contiguous sequence of characters within a string.


Example 1:
Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.

Example 2:
Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It is the only correct answer in this case.


Constraints:
0 <= a, b, c <= 100
a + b + c > 0


*/


// SOURCE CODE


class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});

        string ans = "";
        while(!pq.empty()) {
            auto [count1, char1] = pq.top();
            pq.pop();

            if(ans.size() >= 2 && ans.back() == char1 && ans[ans.size()-2] == char1) {
                if(pq.empty()) break;

                auto [count2, char2] = pq.top();
                pq.pop();

                ans += char2;
                count2--;

                if(count2 > 0) pq.push({count2, char2});
                pq.push({count1, char1});
                
            } else {
                ans += char1;
                count1--;

                if(count1 > 0) pq.push({count1, char1});
            }
        }

        return ans;
    }
};
