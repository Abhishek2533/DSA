/*

Company Tags:

        Flipkart
        Morgan Stanley
        Amazon
        Microsoft
        Samsung
        D-E-Shaw
        Ola Cabs
        Oracle
        Intuit
        Adobe
        Google
        SAP Labs
        Facebook
        Yahoo
        Belzabar
        Apple


*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        priority_queue<int> leftHeap;
        priority_queue<int, vector<int>, greater<int>> rightHeap;
        
        vector<double> res;
        
        for(int i=0; i<arr.size(); i++) {
            leftHeap.push(arr[i]);
            
            int temp=leftHeap.top();
            leftHeap.pop();
            rightHeap.push(temp);
            
            if(rightHeap.size()>leftHeap.size()) {
                temp=rightHeap.top();
                rightHeap.pop();
                leftHeap.push(temp);
            }
            
            double median;
            if(leftHeap.size()!=rightHeap.size()) median=leftHeap.top();
            else median=(double)(leftHeap.top()+rightHeap.top())/2;
            
            res.push_back(median);
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

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends