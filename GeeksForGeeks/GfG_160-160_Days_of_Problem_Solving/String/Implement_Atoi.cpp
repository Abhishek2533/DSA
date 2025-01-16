/*

Company Tags:

        Morgan Stanley
        Amazon
        Microsoft
        Payu
        Adobe
        Code Brew


*/



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
        int ans=0, sign=1, ind=0;

        while(s[ind] == ' ') ind++;
        
        if(s[ind] == '-' || s[ind]=='+') {
            if(s[ind] == '-') sign=-1;
            ind++;
        }
        
        while(s[ind]>='0' && s[ind]<='9') {
            if(ans>INT_MAX/10 || (ans == INT_MAX/10 && s[ind]-'0'>7)) 
                return sign==-1 ? INT_MIN : INT_MAX;
            ans = ans*10 + s[ind]-'0';
            ind++;
        }
        
        return sign*ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends