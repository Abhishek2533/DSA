// METHOD 1:

//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isPalindrome(string& s, int i, int j) {
        while(i<j) {
            if(s[i]!=s[j]) return false;
            i++, j--;
        }
        return true;
    }
    int minChar(string& s) {
        // Write your code here
        int cnt=0, i=s.length()-1;
        
        while(i>=0 && !isPalindrome(s, 0, i)) {
            i--, cnt++;
        }
        
        return cnt;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends








// METHOD 2:

//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> computeLps(string& s) {
        int n = s.length();
        vector<int> lps(n, 0); // Initialize LPS array
        int len = 0, i = 1;    // Start with the second character
        
        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    int minChar(string& s) {
        int n = s.length();
        string rev = s;
        reverse(rev.begin(), rev.end());

        // Create the new string for LPS calculation
        string combined = s + "$" + rev;

        // Compute LPS for the combined string
        vector<int> lps = computeLps(combined);

        // Minimum characters to add = total length of original string - longest palindromic prefix
        return n - lps.back();
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends