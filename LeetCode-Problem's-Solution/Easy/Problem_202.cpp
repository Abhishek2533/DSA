/*

202. Happy Number

Write an algorithm to determine if a number n is happy.
A happy number is a number defined by the following process:
Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.


Example 1:
Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Example 2:
Input: n = 2
Output: false


Constraints: 1 <= n <= 231 - 1

*/

// SOURCE CODE

class Solution
{
private:
    // Function to find the sum of squares of digits of a number
    int sqsum(int num)
    {
        int sum = 0;
        while (num)
        {
            int digit = num % 10;
            sum += digit * digit;
            num /= 10;
        }
        return sum;
    }

public:
    bool isHappy(int n)
    {
        int num = n;
        unordered_set<int> map;

        // Loop to check if the number is happy or not
        while (num != 1)
        {
            if (map.count(num) && !map.empty())
            {                 // Check if number is already in the set
                return false; // Cycle detected, not a happy number
            }
            map.insert(num);  // Insert the number into the set
            num = sqsum(num); // Calculate the sum of squares of digits
        }

        return true; // Number is happy (converged to 1)
    }
};