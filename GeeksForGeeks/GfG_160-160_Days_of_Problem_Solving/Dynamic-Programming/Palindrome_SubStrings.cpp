/*

Company Tags:

        Morgan Stanley
        Amazon
        Ola Cabs
        SAP Labs


*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int countPS(string &s) {
        // code here
        int res=0;
        int n=s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        for(int diff=0; diff<n; diff++) {
            for(int i=0, j=i+diff; j<n; i++, j++) {
                if(i==j) dp[i][j]=true;
                else if(diff==1 && s[i]==s[j]) dp[i][j]=true, res++;
                else {
                    if(s[i]==s[j] && dp[i+1][j-1]) dp[i][j]=true, res++;
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
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends