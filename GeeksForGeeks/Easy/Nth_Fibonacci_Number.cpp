//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int nthFibonacci(int n)
    {
        // code here
        const int MOD = 1000000007;
        if (n == 1 || n == 2)
            return 1;

        long long prev1 = 1, prev2 = 1;
        long long curr;

        for (int i = 3; i <= n; ++i)
        {
            curr = (prev1 + prev2) % MOD;
            prev1 = prev2;
            prev2 = curr;
        }

        return curr;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends