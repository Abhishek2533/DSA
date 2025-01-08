//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        int count1=0, count2=0, ele1, ele2;
        
        for(int i=0; i<arr.size(); i++) {
            if(count1==0 && arr[i] != ele2) {
                count1++;
                ele1=arr[i];
            } else if(count2==0 && arr[i] != ele1) {
                count2++;
                ele2=arr[i];
            } else if(arr[i] == ele1) count1++;
            else if(arr[i] == ele2) count2++;
            else count1--, count2--;
        }
        
        vector<int> ans;
        count1=0, count2=0;
        
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] == ele1) count1++;
            else if(arr[i] == ele2) count2++;
        }
        
        if(count1>arr.size()/3) ans.push_back(ele1);
        if(count2>arr.size()/3) ans.push_back(ele2);
        
        sort(ans.begin(), ans.end());
        return ans;
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
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends