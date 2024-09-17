//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int getMinDiff(vector<int> &arr, int k)
    {
        // code here
        int n = arr.size();

        sort(arr.begin(), arr.end());

        int ans = arr[n - 1] - arr[0];
        int small = arr[0] + k;
        int large = arr[n - 1] - k;

        int mini, maxi;

        for (int i = 0; i < n; i++)
        {
            mini = min(small, arr[i + 1] - k);
            maxi = max(large, arr[i] + k);

            if (mini >= 0)
                ans = min(ans, maxi - mini);
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends