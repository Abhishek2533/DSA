//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    long long revNo(long long num)
    {
        long long rev = 0;
        long long reminder = 0;
        while (num != 0)
        {
            reminder = num % 10;
            rev = rev * 10 + reminder;
            num = num / 10;
        }
        return rev;
    }

    long long isSumPalindrome(long long n)
    {
        // code here
        long long add = 0;
        if (revNo(n) == n)
            return n;
        for (int i = 0; i < 5; i++)
        {
            add = n + revNo(n);

            if (revNo(add) == add)
                return add;
            else
                n = (add);
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        Solution ob;
        cout << ob.isSumPalindrome(n) << endl;
    }
    return 0;
}

// } Driver Code Ends