// METHOD 1: RECURSION

class Solution {
  public:
    int solve(vector<int>& arr, int i, int j) {
        if(i>j) return 0;
        if(i==j) return arr[j];
        
        int pick = arr[j]+solve(arr, i, j-2);
        int not_pick = solve(arr, i, j-1);
        
        return max(pick, not_pick);
    }
  
    int maxValue(vector<int>& arr) {
        // your code here
        int n=arr.size(), ans=0;
        
        ans=max(ans, solve(arr, 0, n-2));
        ans=max(ans, solve(arr, 1, n-1));
        
        return ans;
    }
};










// METHOD 2: MEMOIZATION

class Solution {
  public:
    int solve(vector<int>& arr, int i, int j, vector<int>& dp) {
        if(i>j) return 0;
        if(i==j) return arr[j];
        if(dp[j] != -1) return dp[j];
        
        int pick = arr[j]+solve(arr, i, j-2, dp);
        int not_pick = solve(arr, i, j-1, dp);
        
        return dp[j] = max(pick, not_pick);
    }
  
    int maxValue(vector<int>& arr) {
        // your code here
        int n=arr.size(), ans=0;
        vector<int> dp(n, -1);
        
        ans=max(ans, solve(arr, 0, n-2, dp));
        
        for(int i=0; i<n; i++) dp[i]=-1;
        
        ans=max(ans, solve(arr, 1, n-1, dp));
        
        return ans;
    }
};









// METHOD 3: TABULATION

class Solution {
  public:
    int solve(vector<int>& arr, int i, int j) {
        int n=arr.size();
        vector<int> dp(n);
        
        dp[i]=arr[i];
        dp[i+1] = max(arr[i], arr[i+1]);
        
        for(int x=i+2; x<=j; x++) dp[x]=max(arr[x]+dp[x-2], dp[x-1]);
        
        return dp[j];
    }
  
    int maxValue(vector<int>& arr) {
        // your code here
        int n=arr.size();
        if(n==0) return 0;
        if(n==1) return arr[0];
        
        int ans=0;
        
        ans=max(ans, solve(arr, 0, n-2));
        ans=max(ans, solve(arr, 1, n-1));
        
        return ans;
    }
};









// METHOD 4: TABULATION (SPACE OPTIMIZATION)

class Solution {
  public:
    int solve(vector<int>& arr, int i, int j) {
        int n=arr.size();
        
        int prev2=arr[i];
        int prev1 = max(arr[i], arr[i+1]);
        
        for(int x=i+2; x<=j; x++) {
            int curr=max(arr[x]+prev2, prev1);
            prev2=prev1;
            prev1=curr;
        }
        
        return prev1;
    }
  
    int maxValue(vector<int>& arr) {
        // your code here
        int n=arr.size();
        if(n==0) return 0;
        if(n==1) return arr[0];
        
        int ans=0;
        
        ans=max(ans, solve(arr, 0, n-2));
        ans=max(ans, solve(arr, 1, n-1));
        
        return ans;
    }
};
