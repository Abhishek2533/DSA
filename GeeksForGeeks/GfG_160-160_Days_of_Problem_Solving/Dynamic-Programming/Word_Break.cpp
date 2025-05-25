/*

Company Tags:

        Zoho
        Flipkart
        Amazon
        Microsoft
        Hike
        Walmart
        MAQ Software
        Google
        IBM


*/



// METHOD 1: RECURSION

class Solution {
  public:
    bool solve(int i, string &s, vector<string> &dictionary) {
        if(i==s.length()) return true;
        int n=s.length();
        string prefix="";
        
        for(int j=i; j<n; j++) {
            prefix+=s[j];
            
            if(find(dictionary.begin(), dictionary.end(), prefix) != dictionary.end() && solve(j+1, s, dictionary)) return true;
        }
        
        return false;
    }
    
    bool wordBreak(string &s, vector<string> &dictionary) {
        // code here
        return solve(0, s, dictionary);
    }
};









// METHOD 2: TABULATION

class Solution {
  public:
    bool wordBreak(string &s, vector<string> &dictionary) {
        // code here
        int n=s.length();
        vector<bool> dp(n+1, 0);
        dp[0]=1;
        
        for(int i=1; i<=n; i++) {
            for(string& w : dictionary) {
                int start=i-w.size();
                if(start>=0 && dp[start] && s.substr(start, w.size()) == w) {
                    dp[i]=1;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};