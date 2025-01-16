/*

Company Tags:

        Flipkart
        Amazon
        Microsoft
        D-E-Shaw
        MakeMyTrip
        Ola Cabs
        Payu
        Teradata
        Goldman Sachs
        MAQ Software
        InfoEdge
        OATS Systems
        Tejas Network

        
*/





//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) {
        // Your code here
        vector<int> charArr(26, 0);
        for(int i=0; i<s.size(); i++) charArr[s[i]-'a']++;
        for(int i=0; i<s.size(); i++) if(charArr[s[i]-'a']==1) return s[i];
        return '$';
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;

    while (T--) {

        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonRepeatingChar(S);

        if (ans != '$')
            cout << ans;
        else
            cout << "-1";

        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends