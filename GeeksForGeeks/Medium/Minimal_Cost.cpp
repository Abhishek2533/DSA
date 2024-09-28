// RECURRSION

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(int idx, int n, int k, vector<int>& arr) {
        if(idx == n-1) return 0;
        
        int minCost = INT_MAX;
        
        for(int i=1; i<=k; i++) {
            if(idx+i < n) {
                int p = abs(arr[idx] - arr[idx+i]) + f(idx+i, n, k, arr);
                minCost = min(minCost, p);
            }
        }
        return minCost;
    }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n=arr.size();
        int cost;
        return f(0,n,k,arr);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends






// OPTIMAl

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int f(int index, vector<int> &arr, int n, int k, vector<int> &dp)
    {
        if (index == n - 1)
            return 0;
        if (dp[index] != -1)
            return dp[index];

        int minCost = INT_MAX;

        for (int i = 1; i <= k; i++)
        {
            if (index + i < n)
            {
                int cost = abs(arr[index] - arr[index + i]) + f(index + i, arr, n, k, dp);
                minCost = min(minCost, cost);
            }
        }

        return dp[index] = minCost;
    }

    int minimizeCost(vector<int> &arr, int &k)
    {
        // Code here

        int n = arr.size();
        vector<int> dp(n + 1, -1);
        return f(0, arr, n, k, dp);
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(arr, k);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends