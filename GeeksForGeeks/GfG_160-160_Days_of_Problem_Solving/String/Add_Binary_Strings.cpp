/*

Company Tags:

        Amazon
        Microsoft
        Facebook


*/




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        string res="";
        int i=s1.size()-1, j=s2.size()-1, carry=0;
        
        while(i>=0 || j>=0 || carry>0) {
            int bit1=(i>=0) ? s1[i--]-'0' : 0;
            int bit2=(j>=0) ? s2[j--]-'0' : 0;
            
            int sum=bit1+bit2+carry;
            res+=(sum%2)+'0';
            carry=sum/2;
        }
        
        reverse(res.begin(), res.end());
        if(res[0]=='0'){
            i=0;
            while(res[i]=='0')i++;
            res=res.substr(i);
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends