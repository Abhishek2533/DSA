/*

Company Tags:
        Adobe


*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int count=0;
        int l=0, r=arr.size()-1;
        
        while(l<r) {
            int sum=arr[l]+arr[r];
            
            if(sum<target) l++;
            else if(sum>target) r--;
            else {
                int cnt1=0, cnt2=0;
                int ele1=arr[l], ele2=arr[r];
                
                while(l<=r && arr[l]==ele1) {
                    cnt1++, l++;
                }
                
                while(l<=r && arr[r]==ele2) {
                    cnt2++, r--;
                }
                
                if(ele1==ele2) count+=(cnt1*(cnt1-1))/2;
                else count+=(cnt1*cnt2);
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends