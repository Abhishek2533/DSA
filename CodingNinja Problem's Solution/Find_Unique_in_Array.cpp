/*

You have been given an integer array/list(arr) of size N. Where N is equal to [2M + 1].
Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
Your need to find and return that number which is unique in the array/list.

Note:
Unique element is always present in the array/list according to the given condition.


Input Format:
The first line of input contains an integer 'T' denoting the number of test cases. Then the test cases follow.
The first line of each test case contains an integer 'N' denoting the size of the array/list.
The second line of each test case contains N space separated integers denoting the elements of the array/list.


Input Format:
First Line : An Integer n (size of Array).
Second Line : N space separated integers denoting the elements of the array/list.


Output Format:
The first line of output contains an integer denoting the unique element present in the array/list.


Constraints:
1 <= T <= 10^2
1 <= N <= 10^3
Time Limit: 1sec


Sample Input 1:
1
7
2 3 1 6 3 6 2

Sample Output 1:
1


Sample Input 2:
2
5
2 4 7 2 7
9
1 3 1 3 6 6 7 10 7

Sample Output 2:
4
10

*/

// SOURCE CODE

int findUnique(int *arr, int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans^arr[i];
    }
    return ans;
}