/*

Company Tags:

            Bloomberg
            Facebook
            Intel
            Infosys
            Zoho
            Morgan Stanley
            Amazon
            Microsoft
            Samsung
            Yahoo
            PayPal
            Nvidia
            Oracle
            Visa
            Walmart
            Goldman Sachs
            TCS
            Adobe
            Google
            IBM
            Accenture
            Apple
            Uber


*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int ans=0, buy=prices[0];
        for(int i=1; i<prices.size(); i++) {
            buy = min(buy, prices[i]);
            ans=max(ans, prices[i]-buy);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends