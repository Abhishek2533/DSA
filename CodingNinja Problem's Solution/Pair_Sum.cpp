/*

You are given an integer array ARR of size N and an integer S. Your task is to return the list of all pairs of elements such that each sum of elements of each pair equals S.


Note:
Each pair should be sorted i.e., the first value should be less than or equals to the second value.
Return the list of pairs sorted in non-decreasing order of the their first value.
In case if two pairs have the same value, the pair with a smaller second value should come first.

Input Format:
The first line of input contains two space-separated integers n and S, denoting the size of the input arra and the value of S.
The second and the last line of input contains N space-separated integers, denoting the elements of the input array: ARR[i] where 0 <= i < N.

Output Format:
Print C lines, each line contains one pair i.e., two space-separarted integers, where C denotes the count of pairs having sum equals to given value S.


Note:
You are not required to print the output, it has already been taken care of, just implement the functions.


Constraints:
1 <= N <= 10^3
-10^5 <= ARR[i] <= 10^5
-2*10^5 <= S <= 2*10^5
Time Limit: 1 sec


Sample Input 1:
5 5
1 2 3 4 5

Sample Output 1:
1 4
2 3

    Explanation:
    Here, 1 + 4 = 5
          2 + 3 = 5
    Hence the output will be , (1,4), (2,3).

Sample Input 2:
5 0
2 -3 3 3 -2

Sampl Output 2:
-3 3
-3 3
-2 2


*/

// SOURCE CODE

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    vector< vector<int> > ans;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == s)
            {
                vector<int> temp;
                temp.push_back(min(arr[i], arr[j])); 
                temp.push_back(max(arr[i], arr[j]));
                ans.push_back(temp);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    

}