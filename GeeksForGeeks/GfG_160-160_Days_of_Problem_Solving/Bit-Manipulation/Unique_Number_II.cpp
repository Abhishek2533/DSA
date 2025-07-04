/*

Company Tags:

        Accolite
        Amazon
        Microsoft
        Samsung
        FactSet
        MakeMyTrip
        Google
        Qualcomm


*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        // Code here.
        unordered_map<int, int> mpp;
        vector<int> res;
        
        for(int num : arr) mpp[num]++;
        for(auto& it : mpp) if(it.second==1) res.push_back(it.first);
        
        sort(res.begin(), res.end());
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.singleNum(arr);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends