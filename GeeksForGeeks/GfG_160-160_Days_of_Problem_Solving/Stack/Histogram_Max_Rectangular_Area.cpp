/*

Company Tags:

        Microsoft
        Google


*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int maxi=0;
        stack<int> st;
        
        for(int i=0; i<arr.size(); i++) {
            while(!st.empty() && arr[st.top()]>arr[i]) {
                int curr = st.top();
                st.pop();
                int nse=i;
                int pse=st.empty() ? -1 : st.top();
                maxi=max(maxi, arr[curr]*(nse-pse-1));
            }
            st.push(i);
        }
        
        // TC -> O(N) for traversing array + O(N) for push & pop in stack (overall)
        // SC -> O(N) for stack
        
        while(!st.empty()) {
            int curr=st.top();
            st.pop();
            int nse=arr.size();
            int pse = st.empty() ? -1 : st.top();
            maxi=max(maxi, arr[curr]*(nse-pse-1));
        }
        
        return maxi;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends