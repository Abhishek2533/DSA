//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    long long fact(long x)
    {
        if (x == 0)
        {
            return 1;
        }
        else
        {
            return (long)(x * fact(x - 1));
        }
    }
    long long nPr(int n, int r)
    {
        // code here
        long long ans = fact(n) / fact(n - r);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nPr(n, r) << endl;
    }
    return 0;
}
// } Driver Code Ends