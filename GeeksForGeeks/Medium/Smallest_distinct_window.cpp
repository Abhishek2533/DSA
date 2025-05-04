//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int findSubString(string &str)
    {
        // code here
        int k = set<char>(str.begin(), str.end()).size();

        unordered_map<char, int> mpp;
        int i = 0, j = 0, res = INT_MAX;
        while (j < str.size())
        {
            mpp[str[j]]++;
            if (mpp.size() == k)
            {
                while (mpp[str[i]] > 1)
                {
                    mpp[str[i]]--;
                    i++;
                }
                res = min(res, j - i + 1);
            }
            j++;
        }

        return res;
    }
};

//{ Driver Code Starts.
//      Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends