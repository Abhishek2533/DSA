/*

Company Tags:

        Amazon
        Microsoft
        Goldman Sachs
        Google


*/


// METHOD 1: RECURSION

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int i, int j, string& s1, string& s2) {
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        if(s1[i]==s2[j]) return solve(i-1, j-1, s1, s2);
        return 1+min(solve(i-1, j-1, s1, s2), min(solve(i-1 ,j, s1, s2), solve(i, j-1, s1, s2)));
    }
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        int n=s1.size();
        int m=s2.size();
        return solve(n-1, m-1, s1, s2);
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends









// METHOD 2: MEMOIZATION

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    public:
    int solve(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i]==s2[j]) return dp[i][j]=solve(i-1, j-1, s1, s2, dp);
        return dp[i][j]=1+min(solve(i-1, j-1, s1, s2, dp), min(solve(i-1 ,j, s1, s2, dp), solve(i, j-1, s1, s2, dp)));
    }
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, s1, s2, dp);
    }
};


//{ Driver Code Starts.

int main() {
    
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends










// METHOD 3: TABULATION

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i=0; i<=n; i++) dp[i][0]=i;
        for(int j=0; j<=m; j++) dp[0][j]=j;
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=1+min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }
        return dp[n][m];
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends