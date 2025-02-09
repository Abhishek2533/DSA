/*

Company Tags:
        Ola Cabs


*/



//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        vector<int> res;
        sort(arr.begin(), arr.end());
        int l=0, r=arr.size()-1;
        int minDiff=INT_MAX;
        
        while(l<r) {
            int sum=arr[l]+arr[r];
            int diff =  abs(target-sum);
            
            if(diff<minDiff) {
                minDiff=diff;
                res = {arr[l], arr[r]};
            }
            
            if(sum<target) l++;
            else if(sum>target) r--;
            else return res;
        }
        
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
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends