/*

Company Tags:

        Amazon
        Facebook


*/



// METHOD 1: RECURSION

class Solution {
  public:
    int solve(vector<int>& prices, int idx) {
        int mini=prices[idx], res=0;
        
        for(int i=idx+1; i<prices.size(); i++) {
            mini=min(mini, prices[i]);
            res=max(res, prices[i]-mini);
        }
        
        return res;
    }
    
    int maxProfit(vector<int> &prices) {
        // code here
        int n=prices.size();
        int mini=prices[0], res=0;
        
        for(int i=1; i<n; i++) {
            if(prices[i]>mini) {
                int curr=prices[i]-mini + solve(prices, i);
                res=max(res, curr);
            } else mini=min(mini, prices[i]);
        }
        
        return res;
    }
};








// METHOD 2: TABULATION

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int n=prices.size();
        if(n==0) return 0;
        
        vector<vector<int>> curr(3, vector<int>(2, 0));
        vector<vector<int>> next(3, vector<int>(2, 0));
        
        for(int i=n-1; i>=0; i--) {
            for(int k=1; k<=2; k++) {
                curr[k][1] = max(next[k][0] - prices[i], next[k][1]);
                curr[k][0] = max(next[k-1][1] + prices[i], next[k][0]);
            }
            
            next=curr;
        }
        
        return curr[2][1];
    }
};