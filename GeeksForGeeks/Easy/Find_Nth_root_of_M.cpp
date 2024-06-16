//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int NthRoot(int n, int m)
    {
        // Code here.
        int low = 1, high = m;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            long long cur = 1;
            for (int i = 0; i < n; ++i)
            {
                cur *= mid;
                if (cur > m)
                    break;
            }
            if (cur == m)
                return mid;
            else if (cur < m)
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.NthRoot(n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends