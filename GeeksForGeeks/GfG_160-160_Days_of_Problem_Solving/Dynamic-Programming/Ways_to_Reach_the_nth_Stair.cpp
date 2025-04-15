/*

Company Tags:

        Flipkart
        Amazon
        Microsoft
        OYO Rooms
        Adobe


*/


// METHOD 1: RECURSION

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countWays(int n) {
        // your code here
        if(n==1) return 1;
        if(n==2) return 2;
        
        return countWays(n-1)+countWays(n-2);
    }
};



//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends









// METHOD 2: MEMOIZATION

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int n, vector<int>& dp) {
        if(n==1 || n==2) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=solve(n-1, dp)+solve(n-2, dp);
    }
    int countWays(int n) {
        // your code here
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};



//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends










// METHOD 3: TABULATION

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    public:
    int countWays(int n) {
        // your code here
        vector<int> dp(n+1, 0);
        dp[1]=1, dp[2]=2;
        for(int i=3; i<=n; i++) {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};



//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array
        
        cout << "~"
        << "\n";
    }
    return 0;
}

// } Driver Code Ends














// METHOD 4: TABULATION (SPACE OPTIMIZE)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countWays(int n) {
        // your code here
        if(n==1 || n==2) return n;
        
        int res=0;
        int prev1=1, prev2=2;
        
        for(int i=3; i<=n; i++) {
            res=prev1+prev2;
            prev1=prev2;
            prev2=res;
        }
        return res;
    }
};



//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends