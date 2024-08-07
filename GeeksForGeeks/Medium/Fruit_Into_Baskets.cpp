//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int totalFruits(int N, vector<int> &fruits)
    {
        map<int, int> mpp;
        int l = 0, r = 0, maxLen = 0;
        while (r < N)
        {
            mpp[fruits[r]]++;
            if (mpp.size() > 2)
            {
                mpp[fruits[l]]--;
                if (mpp[fruits[l]] == 0)
                    mpp.erase(fruits[l]);
                l++;
            }
            if (mpp.size() <= 2)
                maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
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
        vector<int> fruits(N);
        for (int i = 0; i < N; i++)
            cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends