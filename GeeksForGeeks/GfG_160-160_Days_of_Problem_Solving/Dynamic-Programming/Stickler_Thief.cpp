/*

Company Tags:

        Paytm
        Flipkart
        Amazon
        OYO Rooms
        Walmart
        Google


*/





// METHOD 1: RECURSION

class Solution {
  public:
    int solve(vector<int>& arr, int n) {
        if(n<=0) return 0;
        if(n==1) return arr[0];
        
        int pick=arr[n-1]+solve(arr, n-2);
        int not_pick=solve(arr, n-1);
        
        return max(pick, not_pick);
    }
  
    int findMaxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        return solve(arr, n);
    }
};








// METHOD 2: MEMOIZATION

class Solution {
  public:
    int solve(vector<int>& arr, int n, vector<int>& dp) {
        if(n<=0) return 0;
        if(n==1) return arr[0];
        if(dp[n] != -1) return dp[n];
        
        int pick=arr[n-1]+solve(arr, n-2, dp);
        int not_pick=solve(arr, n-1, dp);
        
        dp[n] = max(pick, not_pick);
        return dp[n];
    }
  
    int findMaxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> dp(n+1, -1);
        return solve(arr, n, dp);
    }
};









// METHOD 3: TABULATION

class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = arr[0];
        
        for(int i=2; i<=n; i++) dp[i] = max(arr[i-1] + dp[i-2], dp[i-1]);
        
        return dp[n];
    }
};










// METHOD 4: TABULATION (SPACE OPTIMIZED)

class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        int secondLast = 0;
        int last = arr[0];
        int res;
        
        for(int i=1; i<n; i++) {
            res = max(arr[i] + secondLast, last);
            secondLast=last;
            last=res;
        }
        
        return res;
    }
};