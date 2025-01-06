/*

282. Expression Add Operators


Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.
Note that operands in the returned expressions should not contain leading zeros.


Example 1:
Input: num = "123", target = 6
Output: ["1*2*3","1+2+3"]
Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.

Example 2:
Input: num = "232", target = 8
Output: ["2*3+2","2+3*2"]
Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.

Example 3:
Input: num = "3456237490", target = 9191
Output: []
Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.


Constraints:
1 <= num.length <= 10
num consists of only digits.
-231 <= target <= 231 - 1


*/


// SOURCE CODE


class Solution {
public:
    void solve(int index, long long currVal, long long prevVal, string& temp, string& num, int target, vector<string>& ans) {
        if (index == num.size() && currVal == target) return ans.push_back(temp);

        for (int j = index; j < num.size(); j++) {
            // Avoid numbers with leading zeros
            if (j>index && num[index]=='0') break;

            string part = num.substr(index, j-index+1);
            long long currNum = stoll(part);

            if (index == 0) {
                // First number, no operator
                temp += part;
                solve(j + 1, currNum, currNum, temp, num, target, ans);
                temp.erase(temp.size() - part.size());
            } else {
                // Addition
                temp += "+" + part;
                solve(j+1, currVal+currNum, currNum, temp, num, target, ans);
                temp.erase(temp.size() - part.size() - 1);

                // Subtraction
                temp += "-" + part;
                solve(j+1, currVal-currNum, -currNum, temp, num, target, ans);
                temp.erase(temp.size() - part.size() - 1);

                // Multiplication
                temp += "*" + part;
                solve(j+1, currVal-prevVal+(prevVal*currNum), prevVal*currNum, temp, num, target, ans);
                temp.erase(temp.size()-part.size()-1);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string temp;
        solve(0, 0, 0, temp, num, target, ans);
        return ans;
    }
};