//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    string armstrongNumber(int n)
    {
        // code here
        int temp = n, sum = 0;
        while (temp > 0)
        {
            int x = pow((temp % 10), 3);
            sum += x;
            temp /= 10;
        }
        if (sum == n)
            return "true";
        else
            return "false";
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
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends