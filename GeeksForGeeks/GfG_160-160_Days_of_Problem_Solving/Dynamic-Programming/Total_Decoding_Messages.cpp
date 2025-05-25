/*

Company Tags:

        Zoho
        Flipkart
        Morgan Stanley
        Amazon
        Microsoft
        OYO Rooms
        MakeMyTrip
        Goldman Sachs
        Nutanix
        Linkedin
        Facebook


*/


// METHOD 1: 


class Solution {
  public:
    int solve(string& digits, int i) {
        int n=digits.length();
        if(i>=n) return 1;
        
        int ways=0;
        
        if(digits[i] != '0') ways=solve(digits, i+1);
        
        if((i+1 < n) && ((digits[i]=='1' && digits[i+1]<='9') || (digits[i]=='2' && digits[i+1]<='6'))) 
            ways+=solve(digits, i+2);
            
        return ways;
    }
  
    int countWays(string &digits) {
        // Code here
        return solve(digits, 0);
    }
};










// METHOD 2: MEMOIZATION

class Solution {
  public:
    int solve(string& digits, int i, vector<int>& dp) {
        int n=digits.length();
        if(i>=n) return 1;
        if(dp[i] != -1) return dp[i];
        
        int ways=0;
        
        if(digits[i] != '0') ways=solve(digits, i+1, dp);
        
        if((i+1 < n) && ((digits[i]=='1' && digits[i+1]<='9') || (digits[i]=='2' && digits[i+1]<='6'))) 
            ways+=solve(digits, i+2, dp);
            
        dp[i]=ways;
        return ways;
    }
  
    int countWays(string &digits) {
        // Code here
        vector<int> dp(digits.length(), -1);
        return solve(digits, 0, dp);
    }
};








// METHOD 3: TABULATION

class Solution {
  public:
    int countWays(string &digits) {
        // Code here
        int n =digits.length();
        vector<int> dp(n+1, 0);
        dp[n]=1;
        
        for(int i=n-1; i>=0; i--) {
            if(digits[i] != '0') dp[i]=dp[i+1];
        
            if((i+1 < n) && ((digits[i]=='1' && digits[i+1]<='9') || (digits[i]=='2' && digits[i+1]<='6'))) 
                dp[i]+=dp[i+2];
        }
        
        return dp[0];
    }
};