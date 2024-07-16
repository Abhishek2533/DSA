//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int gcd(int a, int b)
    {
        // code here
        int x = max(a, b);
        int y = min(a, b);

        if (x % y == 0)
            return y;
        else
        {
            while (x % y != 0)
            {
                int r = x % y;
                x = y;
                y = r;
            }
            return y;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int a;
        scanf("%d", &a);

        int b;
        scanf("%d", &b);

        Solution obj;
        int res = obj.gcd(a, b);

        cout << res << endl;
    }
}

// } Driver Code Ends