class Solution {
  public:
    int lps(string& s, string& r, int i, int j, vector<vector<int>>& dp) {
        if(i==s.size() || j==r.size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int take=0, not_take=0;
        if(s[i]==r[j]) take= 1+lps(s, r, i+1, j+1, dp);
        else not_take=max(lps(s, r, i+1, j, dp), lps(s, r, i, j+1, dp));
        
        return dp[i][j] = max(take, not_take);
    }
    
    int minDeletions(string s) {
        // code here
        int n=s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        string r=s;
        reverse(r.begin(), r.end());
        return s.size()-lps(s,r,0,0, dp);
    }
};