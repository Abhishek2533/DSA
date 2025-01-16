/*

Company Tags:

        Flipkart
        Directi
        Adobe
        Google
        Nagarro
        Media.net


*/





//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        vector<int> charArr(26,0);
        for(int i=0; i<s1.size(); i++) charArr[s1[i]-'a']++;
        for(int i=0; i<s2.size(); i++) charArr[s2[i]-'a']--;
        for(int i=0; i<charArr.size(); i++) if(charArr[i] != 0) return false;
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends