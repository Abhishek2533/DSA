/*

Company Tags:

            Paytm
            Flipkart
            Morgan Stanley
            Accolite
            Amazon
            Microsoft
            Samsung
            D-E-Shaw
            Hike
            MakeMyTrip
            Ola Cabs
            Oracle
            Walmart
            Goldman Sachs
            Directi
            Intuit
            SAP Labs
            Quikr
            Facebook
            Salesforce
            Pubmatic
            Sapient
            Swiggy


*/

//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int sum=0, i=1;
        for(int i=1; i<prices.size(); i++) {
            if(prices[i]>prices[i-1]) sum+=prices[i]-prices[i-1];
        }
        return sum;
    }
};


//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.maximumProfit(arr);
        cout << res;
        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends