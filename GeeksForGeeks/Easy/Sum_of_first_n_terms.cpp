//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    long long i = 1;
    long long sum = 0;
    long long sumOfSeries(long long n)
    {
        // code here
        if (i > n)
            return sum;
        else
        {
            sum += (i * i * i);
            i++;
            sumOfSeries(n);
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
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.sumOfSeries(N) << "\n";
    }
}
// } Driver Code Ends