//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        unordered_map<int, int> mpp;
        mpp[0]=-1;
        int maxLen=0, prefix=0;
        
        for(int i=0; i<arr.size(); i++) {
            prefix+=(arr[i]>k) ? 1 : -1;
            if(prefix>0) maxLen=i+1;
            if(mpp.find(prefix-1) != mpp.end()) maxLen=max(maxLen, i-mpp[prefix-1]);
            if(mpp.find(prefix) == mpp.end()) mpp[prefix]=i;
        }
        
        return maxLen;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends