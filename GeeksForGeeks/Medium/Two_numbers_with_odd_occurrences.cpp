//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)
    {
        // code here
        vector<long long int> k;
        long long int xorr = 0;
        for (long long int i = 0; i < N; i++)
        {
            xorr = xorr ^ Arr[i];
        }
        long long int rightmost = (xorr & (xorr - 1)) ^ xorr;
        long long int b1 = 0, b2 = 0;
        for (long long int i = 0; i < N; i++)
        {
            if (Arr[i] & rightmost)
                b1 = b1 ^ Arr[i];
            else
                b2 = b2 ^ Arr[i];
        }
        k.push_back(b2);
        k.push_back(b1);
        sort(k.begin(), k.end());
        reverse(k.begin(), k.end());
        return k;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int N;
        cin >> N;
        long long int Arr[N];
        for (long int i = 0; i < N; i++)
            cin >> Arr[i];
        Solution ob;
        vector<long long int> ans = ob.twoOddNum(Arr, N);
        for (long long int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends