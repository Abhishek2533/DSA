//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int sameOccurrence(vector<int> &arr, int x, int y)
    {
        // code here
        int countX = 0;
        int countY = 0;
        int ans = 0;
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        for (int num : arr)
        {
            if (num == x)
                countX++;
            if (num == y)
                countY++;
            int diff = countX - countY;
            if (mpp.find(diff) != mpp.end())
                ans += mpp[diff];
            mpp[diff]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--)
    {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int x = stoi(ks);
        string ks1;
        getline(cin, ks1);
        int y = stoi(ks1);
        Solution ob;
        int ans = ob.sameOccurrence(arr, x, y);
        cout << ans << "\n";
        // cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends