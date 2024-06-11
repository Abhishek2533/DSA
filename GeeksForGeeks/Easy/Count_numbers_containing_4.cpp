//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool containsFour(int num)
    {
        while (num)
        {
            int lastDigit = num % 10;
            if (lastDigit == 4)
            {
                return true;
            }
            num = num / 10;
        }
        return false;
    }

    int countNumberswith4(int n)
    {
        // code here
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (containsFour(i))
            {
                res++;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends