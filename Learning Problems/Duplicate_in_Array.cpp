/*

You are given an array 'ARR' of size 'N' containing each number between 1 and N-1 at least once. There is a single integer value that present in that array twice. Your task is to find the duplicate integer value present in the array.


for example:
Consider ARR = [1, 2, 3, 4, 4], the duplicate integer value present in the array is 4. Hence, the answer is 4 in this case.


note:
A duplicate number is always present in the given array.


Input Format:
The first line of input contains an integer 'T' denoting the number of test cases.
The first line of each test case contains a single integer 'N' denoting the number of elements in the array.
The second line of each test case contains 'N' space-separated integers denoting the elements of the array 'ARR'.


Output Format:

For each test case, print a single integer - the duplicate element in the array.
Print the output of the each test case in a separate line.

Constraints:
1 <= T <= 10
2 <= N <= 10^5
1 <= ARR[i] <= N - 1
Where 'T' denotes the number of test cases, 'N' denotes the number of elements in the array, and 'ARR[i]' denotes the 'i-th' element of the array 'ARR'.
Time limit: 1 sec


Sample Input 1:
2
5
4 3 2 1 3 1
7
6 3 1 5 4 3 2

Sample Output 1:
1
3
    Explanation:
    For the first test case, The duplicate integer value present in the array is 1. Hence, the answer is 1 in this case.
    For the second test case, The duplicate integer value present in the array is 3. Hence, the answer is 3 in this case.


Sample Input 2:
2
6
5 1 2 3 4 2
9
8 7 2 5 4 7 1 3 6

Sample Output 2:
2
7


*/

// SOURCE CODE

int findDuplicate(vector<int> &arr)
{
    int ans = 0;

    // XOR all array elements
    for (int i = 0; i < arr.size(); i++)
    {
        ans = ans ^ arr[i];
    }

    // XOR [1 - n-1] elements
    for (int i = 1; i < arr.size(); i++)
    {
        ans = ans ^ i;
    }
    return ans;
}