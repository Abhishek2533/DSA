//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    string removeLeadingZeros(string str) {
        int i = 0;
        while (i < str.length() && str[i] == '0') {
            i++;
        }
        return i == str.length() ? "0" : str.substr(i);
    }

    string multiplyStrings(string& s1, string& s2) {
        bool negative = false;
        
        if (!s1.empty() && s1[0] == '-') {
            negative = !negative;
            s1 = s1.substr(1);
        }
        
        if (!s2.empty() && s2[0] == '-') {
            negative = !negative;
            s2 = s2.substr(1);
        }
        
        s1 = removeLeadingZeros(s1);
        s2 = removeLeadingZeros(s2);
        
        if (s1 == "0" || s2 == "0") return "0";
        
        int n = s1.size();
        int m = s2.size();
        
        vector<int> res(n + m, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (s1[i] - '0') * (s2[j] - '0');
                int sum = mul + res[i + j + 1];
                
                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }
        
        string ans = "";
        int i = 0;
        
        while (i < res.size() && res[i] == 0) {
            i++;
        }
        
        for (; i < res.size(); i++) {
            ans.push_back(res[i] + '0');
        }
        
        if (negative) {
            ans = "-" + ans;
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string a;
        string b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends