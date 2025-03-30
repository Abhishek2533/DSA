/*

Company Tags:

        Amazon
        Microsoft
        Samsung
        Walmart
        Google


*/



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        priority_queue<int, vector<int>, greater<int>> heap(arr.begin(), arr.begin()+k);
        
        for(int i=k; i<arr.size(); i++) {
            if(heap.top()<arr[i]) {
                heap.pop();
                heap.push(arr[i]);
            }
        }
        
        vector<int> res;
        
        while(!heap.empty()) {
            res.push_back(heap.top());
            heap.pop();
        }
        
        reverse(res.begin(), res.end());
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
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.kLargest(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends