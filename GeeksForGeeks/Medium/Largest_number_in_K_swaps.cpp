//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    void solve(string &res, string s, int k, int index)
    {
        if (k == 0 || index >= s.size())
            return;

        char curr = s[index];
        for (int i = index + 1; i < s.size(); i++)
        {
            if (s[i] > curr)
                curr = s[i];
        }

        if (curr != s[index])
            k--;

        for (int i = index; i < s.size(); i++)
        {
            if (curr == s[i])
            {
                swap(s[index], s[i]);
                if (s.compare(res) > 0)
                    res = s;
                solve(res, s, k, index + 1);
                swap(s[index], s[i]);
            }
        }
    }
    // Function to find the largest number after k swaps.
    string findMaximumNum(string &s, int k)
    {
        // code here.
        string res = s;
        solve(res, s, k, 0);
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends