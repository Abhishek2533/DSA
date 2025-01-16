/*

Company Tags:

        Oracle
        Adobe


*/





// METHOD 1:

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        // Your code here
        s1+=s2;
        return s1.find(s2) != string::npos;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) {
            cout << "true" << endl;

        } else {
            cout << "false" << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends





// METHOD 2:

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        // Your code here
        int n=s1.size();
        
        for(int i=0; i<n; i++) {
            if(s1==s2) return true;
            
            char last=s1.back();
            s1.pop_back();
            s1 =last+s1;
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) {
            cout << "true" << endl;

        } else {
            cout << "false" << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends





// METHOD 3:

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> computeArray(string& pat) {
        int n = pat.size();
        vector<int> lps(n, 0);
        
        int len = 0;
        int i = 1;
        
        while (i < n) {
            if (pat[i] == pat[len]) {
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
    
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        // Check if lengths are different
        if (s1.length() != s2.length()) return false;
        
        // Concatenate s1 with itself
        string text = s1 + s1;
        string pat = s2;
        
        int n = text.length(); // Length of concatenated string
        int m = pat.length();  // Length of s2
        
        // Compute LPS array for pattern (s2)
        vector<int> lps = computeArray(pat);
        
        int i = 0, j = 0;
        while (i < n) {
            if (pat[j] == text[i]) {
                i++, j++;
            }
            if (j == m) {
                return true; // Found pattern in text
            } else if (i < n && pat[j] != text[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false; // Pattern not found
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) {
            cout << "true" << endl;

        } else {
            cout << "false" << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends