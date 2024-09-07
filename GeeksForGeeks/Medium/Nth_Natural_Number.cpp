//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    long long findNth(long long n)
    {
        // code here.
        if (n < 9)
            return n;

        long long ans = 0, pos = 1; // initialize to position unit place -> then tens -> then hundreds, -> ...etc
        while (n > 0)
        {
            int rem = n % 9;
            ans += (pos * rem);
            n /= 9;
            pos *= 10;
        }
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
        long long n, ans;
        cin >> n;
        Solution obj;
        ans = obj.findNth(n);
        cout << ans << endl;
    }
}

// } Driver Code Ends