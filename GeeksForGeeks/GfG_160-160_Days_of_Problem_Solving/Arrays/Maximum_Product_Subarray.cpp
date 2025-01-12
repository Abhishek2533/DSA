/*

Company Tags:

        Morgan Stanley
        Amazon
        Microsoft
        OYO Rooms
        D-E-Shaw
        Google


*/



// METHOD 1:

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        int currMax=arr[0], currMin=arr[0], ans=arr[0];
        for(int i=1; i<arr.size(); i++) {
            int temp=max({currMax*arr[i], currMin*arr[i], arr[i]});
            currMin=min({currMax*arr[i], currMin*arr[i], arr[i]});
            currMax=temp;
            ans=max(ans, currMax);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends