//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int greatestOfThree(int A, int B, int C)
    {
        // code here
        if (A > B)
        {
            if (C > A)
                return C;
            else
                return A;
        }
        else
        {
            if (B > C)
                return B;
            else
                return C;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int A, B, C;
        cin >> A >> B >> C;
        Solution ob;
        cout << ob.greatestOfThree(A, B, C) << "\n";
    }
}

// } Driver Code Ends