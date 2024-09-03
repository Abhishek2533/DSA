//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int extractMaximum(string S)
    {
        // code here.
        int maxi = INT_MIN;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] >= '0' && S[i] <= '9')
            {
                int num = 0;
                while (S[i] >= '0' && S[i] <= '9')
                {
                    num = num * 10 + S[i] - '0';
                    i++;
                }
                maxi = max(maxi, num);
            }
        }
        return maxi == INT_MIN ? -1 : maxi;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.extractMaximum(S) << endl;
    }
    return 0;
}
// } Driver Code Ends