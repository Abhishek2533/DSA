/*

Company Tags:

        Zoho
        Accolite
        Amazon
        Microsoft
        OYO Rooms
        Samsung
        Snapdeal
        Citrix
        Walmart
        MAQ Software
        Cisco


*/



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void solve(string& s, int i, vector<string>& res) {
        int n=s.size();
        if(i>=n) return res.push_back(s);
        
        unordered_set<char> st;
        for(int j=i; j<n; j++) {
            if(st.find(s[j])!=st.end()) continue;
            st.insert(s[j]);
            swap(s[j], s[i]);
            solve(s, i+1, res);
            swap(s[j], s[i]);
        }
    }
    vector<string> findPermutation(string &s) {
        // Code here there
        vector<string> res;
        solve(s, 0, res);
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends