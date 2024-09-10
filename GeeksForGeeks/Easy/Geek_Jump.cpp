//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int f(vector<int> &dp, vector<int> &h, int n)
    {
        if (n == 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];

        int left = abs(h[n - 1] - h[n]) + f(dp, h, n - 1);
        int right = INT_MAX;
        if (n > 1)
        {
            right = abs(h[n - 2] - h[n]) + f(dp, h, n - 2);
        }
        dp[n] = min(left, right);
        return dp[n];
    }
    int minimumEnergy(vector<int> &height, int n)
    {
        // Code here
        vector<int> dp(n + 1, -1);
        return f(dp, height, n - 1);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends