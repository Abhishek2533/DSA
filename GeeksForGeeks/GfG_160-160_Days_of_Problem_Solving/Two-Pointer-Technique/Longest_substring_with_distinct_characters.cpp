/*

Company Tags:

        Amazon
        Microsoft
        Housing.com
        Adobe


*/





//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        unordered_map<char, int> freq;
        int maxi=0;
        
        int i=0, j=0;
        while(j<s.size()) {
            freq[s[j]]++;
            
            while(freq[s[j]]>1) {
                freq[s[i]]--;
                i++;
            }
            maxi=max(maxi, j-i+1);
            j++;
        }
        
        return  maxi;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends