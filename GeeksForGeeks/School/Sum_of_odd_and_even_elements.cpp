//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<int> find_sum(int n)
    {
        // Code here
        int odd, even;
        if (n % 2 == 0)
        {
            odd = (n * n) / 4;
            even = (n / 2) * (n / 2 + 1);
        }
        else
        {
            odd = (n + 1) * (n + 1) / 4;
            even = (n + 1) * (n - 1) / 4;
        }

        return {odd, even};
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        Solution ob;
        vector<int> ans = ob.find_sum(n);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends