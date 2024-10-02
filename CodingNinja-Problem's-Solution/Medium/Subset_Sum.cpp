bool solve(int n, int k, vector<int>& a, vector<vector<int>>& dp) {
    if (k == 0) return true;  // Base case: if the sum is 0, return true
    if (n < 0) return false;  // Base case: no elements left to pick, return false
    if (dp[n][k] != -1) return dp[n][k];  // Return memoized result if available
    
    // Case 1: Exclude the current element
    bool exclude = solve(n - 1, k, a, dp);
    
    // Case 2: Include the current element (if it doesn't make the sum negative)
    bool include = (k >= a[n]) ? solve(n - 1, k - a[n], a, dp) : false;
    
    // Store and return the result in dp
    return dp[n][k] = exclude || include;
}   

bool isSubsetPresent(int n, int k, vector<int>& a) {
    // Write your code
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));  // n rows, k+1 columns
    return solve(n - 1, k, a, dp);  // Start solving from the last element
}



// Tabulation - DP

bool isSubsetPresent(int n, int k, vector<int>& a) {
    vector<vector<bool>> dp(n+1, vector<bool>(k+1, false));

    // Base case: A sum of 0 is always possible (by choosing an empty subset).
    for(int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // Fill the dp array
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            dp[i][j] = dp[i-1][j]; // Not including a[i-1]
            if(j >= a[i-1]) {
                dp[i][j] = dp[i][j] || dp[i-1][j-a[i-1]]; // Include a[i-1] if possible
            }
        }
    }

    return dp[n][k];
}
