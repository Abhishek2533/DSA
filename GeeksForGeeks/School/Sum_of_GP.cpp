//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long sum_of_gp(long n, long a, long r)
    {
        // Code here
        if (r == 1)
            return n * a;
        else if (r > 1)
            return (a * (pow(r, n) - 1)) / (r - 1);
        else if (r < 1)
            return (a * (1 - pow(r, n))) / (1 - r);
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long n, a, r;
        cin >> n >> a >> r;
        Solution ob;
        long long int ans = ob.sum_of_gp(n, a, r);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends