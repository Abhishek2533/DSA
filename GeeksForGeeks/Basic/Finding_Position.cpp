//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    long long int nthPosition(long long int n)
    {
        // code here
        int m = log2(n);
        return pow(2, m);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthPosition(n) << endl;
    }
    return 0;
}

// } Driver Code Ends