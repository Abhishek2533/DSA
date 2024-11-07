//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int countOfSubsetSum(vector<int> &arr, long long sum)
    {
        int n = arr.size();
        int MOD = 1000000007;
        vector<vector<int>> t(n + 1, vector<int>(sum + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            t[i][0] = 1;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                    t[i][j] = (t[i - 1][j - arr[i - 1]] + t[i - 1][j]) % MOD;
                else
                    t[i][j] = t[i - 1][j];
            }
        }

        return t[n][sum];
    }

    int countPartitions(int n, int d, vector<int> &arr)
    {
        // Code here
        long long sum = 0;
        for (int num : arr)
            sum += num;

        if ((d + sum) % 2 != 0 || sum < d)
            return 0;

        long long target = (d + sum) / 2;
        return countOfSubsetSum(arr, target);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";

        cout << "~" << "\n";
    }
    return 0;
}
// } Driver Code Ends