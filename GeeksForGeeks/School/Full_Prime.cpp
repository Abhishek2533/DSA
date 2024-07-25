//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int fullPrime(int N)
    {
        // code here
        if (N == 1)
            return 0;

        for (int i = 2; i * i <= N; i++)
        {
            if (N % i == 0)
                return 0;
        }

        while (N > 0)
        {
            if (N % 10 == 0 || N % 10 == 1 || N % 10 == 4 || N % 10 == 6 || N % 10 == 8 || N % 10 == 9)
                return 0;
            N = N / 10;
        }

        return 1;
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
        cout << ob.fullPrime(N) << "\n";
    }
}
// } Driver Code Ends