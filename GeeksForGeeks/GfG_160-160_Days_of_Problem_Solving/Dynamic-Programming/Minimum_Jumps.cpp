/*

Company Tags:

        Moonfrog Labs
        Flipkart
        Amazon
        Microsoft
        Housing.com
        Walmart
        Adobe
        Google


*/

// METHOD 1: RECURSION

class Solution {
  public:
    int solve(int i, vector<int>& arr) {
        if(i>=arr.size()-1) return 0;
        
        int ans=INT_MAX;
        
        for(int j=i+1; j<=i+arr[i]; j++) {
            int val = solve(j, arr);
            if(val!=INT_MAX) ans=min(ans, 1+val);
        }
        
        return ans;
    }
  
    int minJumps(vector<int>& arr) {
        // code here
        int ans = solve(0, arr);
        
        return ans==INT_MAX ? -1 : ans;
    }
};





// METHOD 2: MEMOIZATION

class Solution {
  public:
    int solve(int i, vector<int>& arr, vector<int>& dp) {
        if(i>=arr.size()-1) return 0;
        if(dp[i] != -1) return dp[i];
        
        int ans=INT_MAX;
        
        for(int j=i+1; j<=i+arr[i]; j++) {
            int val = solve(j, arr, dp);
            if(val!=INT_MAX) ans=min(ans, 1+val);
        }
        
        return dp[i]=ans;
    }
  
    int minJumps(vector<int>& arr) {
        // code here
        vector<int> dp(arr.size(), -1);
        int ans = solve(0, arr, dp);
        
        return ans==INT_MAX ? -1 : ans;
    }
};





// METHOD 3: TABULATION

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> dp(n, INT_MAX);
        dp[n-1]=0;
        
        for(int i=n-2; i>=0; i--) {
            for(int j=i+1; j<=i+arr[i] && j<n; j++) {
                if(dp[j] != INT_MAX) dp[i] = min(dp[i], 1+dp[j]);
            }
        }
        
        return dp[0]==INT_MAX ? -1 : dp[0];
    }
};
