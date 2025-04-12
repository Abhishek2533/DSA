/*

Company Tags:

        Paytm
        VMWare
        Amazon
        Microsoft
        Citrix
        MakeMyTrip


*/


// METHOD 1: RECURSION

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(string& s1, int i, string& s2, int j) {
        if(i==s1.size() || j==s2.size()) return 0;
        
        if(s1[i]==s2[j]) return 1+solve(s1, i+1, s2, j+1);
        else return max(solve(s1, i+1, s2, j), solve(s1, i, s2, j+1));
    }
    int lcs(string &s1, string &s2) {
        // code here
        return solve(s1, 0, s2, 0);
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends









// METHOD 2: MEMOIZATION

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(string& s1, int i, string& s2, int j, vector<vector<int>>& dp) {
        if(i==s1.size() || j==s2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=1+solve(s1, i+1, s2, j+1, dp);
        else return dp[i][j]=max(solve(s1, i+1, s2, j, dp), solve(s1, i, s2, j+1, dp));
    }
    int lcs(string &s1, string &s2) {
        // code here
        int n=s1.size(), m=s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(s1, 0, s2, 0, dp);
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends









// METHOD 3: TABULATION

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int lcs(string &s1, string &s2) {
        // code here
        int n=s1.size(), m=s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                if(s1[i]==s2[j]) dp[i][j]=1+dp[i+1][j+1];
                else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        
        return dp[0][0];
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends