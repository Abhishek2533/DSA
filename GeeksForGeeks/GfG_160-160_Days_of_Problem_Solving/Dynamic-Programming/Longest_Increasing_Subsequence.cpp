/*

Company Tags:

        Paytm
        Amazon
        Microsoft
        OYO Rooms
        Samsung
        BankBazaar


*/

// METHODS 1: RECURRSION

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
        int solve(int i, int prev, vector<int> &arr) {
                if (i < 0)
                        return 0;
                int take = 0;
                if (arr[i] < prev)
                        take = 1 + solve(i - 1, arr[i], arr);
                int not_take = solve(i - 1, prev, arr);
                return max(take, not_take);
        }
        int lis(vector<int> &arr) {
                // code here
                return solve(arr.size() - 1, INT_MAX, arr);
        }
};

//{ Driver Code Starts.

int main()
{
        int t;
        cin >> t;
        cin.ignore(); // to ignore the newline after the integer input

        while (t--)
        {
                int n;
                vector<int> arr;
                string input;

                // Input format: first number n followed by the array elements
                getline(cin, input);
                stringstream ss(input);
                int num;
                while (ss >> num)
                        arr.push_back(num);

                Solution obj;
                cout << obj.lis(arr) << endl;
                cout << "~" << endl;
        }

        return 0;
}

// } Driver Code Ends







// METHODS 2: MEMOIZATION

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int i, int prev, vector<int>& arr, vector<vector<int>>& dp) {
        if(i==arr.size()) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        
        int take = 0;
        if(prev==-1 || arr[i]>arr[prev]) take=1+solve(i+1, i, arr, dp);
        int not_take = solve(i+1, prev, arr, dp);
        
        return dp[i][prev+1]=max(take, not_take);
    }
    int lis(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(0, -1, arr, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends









// METHODS 3: TABULATION

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int lis(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> dp(n, 1);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(arr[i]>arr[j] && 1+dp[j]>dp[i]) {
                    dp[i] = 1+dp[j];
                }
            }
        }
        
         return *max_element(dp.begin(), dp.end());
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends