/*

Company Tags:

        Flipkart
        Morgan Stanley
        Accolite
        Amazon
        Microsoft
        D-E-Shaw
        Intuit
        Opera


*/



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int prod=1;
        int zeros=0, idx=-1;
        vector<int> res(arr.size(), 0);
        
        for(int i=0; i<arr.size(); i++) {
            if(arr[i]==0){
                zeros++;
                idx=i;
            }
            else prod*=arr[i];
        }
        
        if(zeros==0) {
            for(int i=0; i<arr.size(); i++) {
                res[i] = prod/arr[i];
            }
        } else if(zeros==1) {
            res[idx]=prod;
        }
        
        return res;
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

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends