// RECURSIVE - TLE

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = 1e9+7;
	int solve(int arr[], int n, int sum) {
	    if(n==0 && sum!=0) return 0;
        if(n==0 && sum==0) return 1;
        
        if(arr[n-1]<=sum)
            return solve(arr,n-1,sum-arr[n-1])%mod + solve(arr,n-1,sum)%mod;
        else
            return solve(arr,n-1,sum)%mod;
	}
	int perfectSum(int arr[], int n, int sum) {
        // Your code goes here
        return solve(arr,n,sum);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends










// DP - MEMOIZATION - TLE

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int mod = 1e9+7;
	
	int solve(int arr[], int n, int sum, vector<vector<int>> &dp){
        if(n==0 && sum!=0) return 0;
        if(n==0 && sum==0) return 1;
        
        if(dp[n][sum]!=-1) return dp[n][sum];
        
        if(arr[n-1]<=sum)
            return dp[n][sum] = solve(arr,n-1,sum-arr[n-1],dp)%mod + solve(arr,n-1,sum,dp)%mod;
        else
            return dp[n][sum] = solve(arr,n-1,sum,dp)%mod;
    }
    
	int perfectSum(int arr[], int n, int sum) {
        // Your code goes here
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return solve(arr,n,sum,dp);
	}
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends








// DP - TABULATION - OPTIMIZE) (ACCEPTED)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int mod = 1e9+7;
	
	 int solve(int arr[], int n, int sum){
        int dp[n+1][sum+1];
        
        for(int i=0; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(i==0) dp[i][j] = 0;
                if(j==0) dp[i][j] = 1;
            }
        }
        
        for(int i=1; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(arr[i-1]<=j)
                    dp[i][j] = dp[i-1][j-arr[i-1]]%mod + dp[i-1][j]%mod;
                else
                    dp[i][j] = dp[i-1][j]%mod;
            }
        }
        return dp[n][sum]%mod;
    }
    
	int perfectSum(int arr[], int n, int sum) {
        // Your code goes here
        return solve(arr,n,sum);
	}
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends