/*

Company Tags:

        Amazon
        Microsoft
        Intuit
        Linkedin


*/


// METHOD 1: RECURSION

// User function Template for C++
class Solution {
  public:
    bool evaluate(char op, bool b1, bool b2) {
        if(op=='&') return b1&b2;
        else if(op=='|') return b1|b2;
        return b1^b2;
    }
  
    int solve(string& s, int i, int j, bool req) {
        if(i==j) return (req==(s[i]=='T')) ? 1 : 0;
        
        int ans=0;
        for(int k=i+1; k<j; k++) {
            int leftTrue=solve(s, i, k-1, 1);
            int leftFalse=solve(s, i, k-1, 0);
            
            int rightTrue=solve(s, k+1, j, 1);
            int rightFalse=solve(s, k+1, j, 0);
            
            if(evaluate(s[k], true, true)==req) ans+=leftTrue*rightTrue;
            if(evaluate(s[k], true, false)==req) ans+=leftTrue*rightFalse;
            if(evaluate(s[k], false, true)==req) ans+=leftFalse*rightTrue;
            if(evaluate(s[k], false, false)==req) ans+=leftFalse*rightFalse;
        }
        
        return ans;
    }
  
    int countWays(string &s) {
        // code here
        int n=s.length();
        return solve(s, 0, n-1, 1);
    }
};









// METHOD 2: MEMOIZATION

// User function Template for C++
class Solution {
  public:
    bool evaluate(char op, bool b1, bool b2) {
        if(op=='&') return b1&b2;
        else if(op=='|') return b1|b2;
        return b1^b2;
    }
  
    int solve(string& s, int i, int j, bool req, vector<vector<vector<int>>>& dp) {
        if(i==j) return (req==(s[i]=='T')) ? 1 : 0;
        if(dp[i][j][req] != -1) return dp[i][j][req];
        
        int ans=0;
        for(int k=i+1; k<j; k++) {
            int leftTrue=solve(s, i, k-1, 1, dp);
            int leftFalse=solve(s, i, k-1, 0, dp);
            
            int rightTrue=solve(s, k+1, j, 1, dp);
            int rightFalse=solve(s, k+1, j, 0, dp);
            
            if(evaluate(s[k], true, true)==req) ans+=leftTrue*rightTrue;
            if(evaluate(s[k], true, false)==req) ans+=leftTrue*rightFalse;
            if(evaluate(s[k], false, true)==req) ans+=leftFalse*rightTrue;
            if(evaluate(s[k], false, false)==req) ans+=leftFalse*rightFalse;
        }
        
        return ans;
    }
  
    int countWays(string &s) {
        // code here
        int n=s.length();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return solve(s, 0, n-1, 1, dp);
    }
};











// METHOD 3: TABULATION

// User function Template for C++
class Solution {
  public:
    bool evaluate(char op, bool b1, bool b2) {
        if(op=='&') return b1&b2;
        else if(op=='|') return b1|b2;
        return b1^b2;
    }
  
    int countWays(string &s) {
        // code here
        int n=s.length();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
        
        for(int i=0; i<n; i+=2) {
            dp[i][i][0] = (s[i]=='F');
            dp[i][i][1] = (s[i]=='T');
        }
        
        for(int len=2; len<n; len+=2) {
            for(int i=0; i<n-len; i+=2) {
                int j=i+len;
                dp[i][j][0]=dp[i][j][1]=0;
                
                for(int k=i+1; k<j; k+=2) {
                    char op=s[k];
                    int leftTrue=dp[i][k-1][1];
                    int leftFalse=dp[i][k-1][0];
                    
                    int rightTrue=dp[k+1][j][1];
                    int rightFalse=dp[k+1][j][0];
                    
                    if(evaluate(op, 1, 1)) dp[i][j][1]+=leftTrue*rightTrue;
                    if(evaluate(op, 1, 0)) dp[i][j][1]+=leftTrue*rightFalse;
                    if(evaluate(op, 0, 1)) dp[i][j][1]+=leftFalse*rightTrue;
                    if(evaluate(op, 0, 0)) dp[i][j][1]+=leftFalse*rightFalse;
                    
                    if(!evaluate(op, 1, 1)) dp[i][j][0]+=leftTrue*rightTrue;
                    if(!evaluate(op, 1, 0)) dp[i][j][0]+=leftTrue*rightFalse;
                    if(!evaluate(op, 0, 1)) dp[i][j][0]+=leftFalse*rightTrue;
                    if(!evaluate(op, 0, 0)) dp[i][j][0]+=leftFalse*rightFalse;
                }
            }
        }
        
        return dp[0][n-1][1];
    }
};