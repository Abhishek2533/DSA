//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int kthDigit(int A, int B, int K)
    {
        // code here
        long long int val = pow(A, B);
        long long int last = 0;
        for (int i = 1; i <= K; i++)
        {
            last = val % 10;
            val = val / 10;
        }
        return last;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int A, B, K;
        cin >> A >> B >> K;
        Solution ob;
        cout << ob.kthDigit(A, B, K) << endl;
    }
    return 0;
}
// } Driver Code Ends