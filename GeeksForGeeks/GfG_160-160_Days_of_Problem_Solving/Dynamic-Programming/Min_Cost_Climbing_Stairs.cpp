// METHOD 1: RECURSION

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
    int solve(int n, vector<int>& cost, vector<int>& memo) {
        if(n==0 || n==1) return cost[n];
        if(memo[n]!=-1) return memo[n];
        return memo[n] = cost[n] + min(solve(n-1, cost, memo), solve(n-2, cost, memo));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int n=cost.size();
        if(n==1) return cost[0];
        vector<int> memo(n+1, -1);
        return min(solve(n-1, cost, memo), solve(n-2, cost, memo));
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends









// METHOD 2: MEMOIZATION

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
    int solve(int n, vector<int>& cost) {
        if(n==0 || n==1) return cost[n];
        return cost[n] + min(solve(n-1, cost), solve(n-2, cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int n=cost.size();
        if(n==1) return cost[0];
        return min(solve(n-1, cost), solve(n-2, cost));
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends










// METHOD 3: TABULATION

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int n=cost.size();
        vector<int> dp(n, 0);
        dp[0]=cost[0];
        dp[1]=cost[1];
        
        for(int i=2; i<n; i++) {
            dp[i]=cost[i]+min(dp[i-1], dp[i-2]);
        }
        
        return min(dp[n-1], dp[n-2]);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends














// METHOD 4: TABULATION (SPACE OPTIMIZE)

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int n=cost.size();
        int prev1=cost[0];
        int prev2=cost[1];
        
        for(int i=2; i<n; i++) {
            int curr=cost[i]+min(prev1, prev2);
            prev1=prev2;
            prev2=curr;
        }
        
        return min(prev1, prev2);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends