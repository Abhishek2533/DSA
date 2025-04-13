/*

Company Tags:

        Zoho
        Accolite
        Amazon
        Microsoft
        Samsung
        MakeMyTrip
        Visa
        Walmart
        Google
        Qualcomm
        Groupon


*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string longestPalindrome(string &s) {
        // code here
        string res;
        int n=s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        int maxLen=0;
        for(int diff=0; diff<n; diff++) {
            for(int i=0, j=i+diff; j<n; i++, j++) {
                if(i==j) dp[i][j]=1;
                else if(diff==1) dp[i][j]=(s[i]==s[j])?2:0;
                else {
                    if(s[i]==s[j] && dp[i+1][j-1]) dp[i][j]=dp[i+1][j-1]+2;
                }
                
                if(dp[i][j] && (j-i+1)>maxLen) {
                    maxLen=j-i+1;
                    res=s.substr(i,maxLen);
                }
            }
        }
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends