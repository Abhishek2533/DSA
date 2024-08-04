//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int isDigitSumPalindrome(int n)
    {
        // code here
        if (n < 10)
            return 1;

        long long sum = 0;
        while (n > 0)
        {
            sum += n % 10;
            n = n / 10;
        }

        long long rev = 0, temp = sum;
        while (temp > 0)
        {
            rev = rev * 10 + temp % 10;
            temp = temp / 10;
        }

        if (rev == sum)
            return 1;
        return 0;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isDigitSumPalindrome(N) << "\n";
    }
}

// } Driver Code Ends