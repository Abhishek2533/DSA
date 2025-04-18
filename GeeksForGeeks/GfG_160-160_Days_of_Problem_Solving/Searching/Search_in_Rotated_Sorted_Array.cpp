/*

Company Tags:

        Paytm
        Flipkart
        Amazon
        Microsoft
        Snapdeal
        D-E-Shaw
        FactSet
        Hike
        MakeMyTrip
        Intuit
        Adobe
        Google
        BankBazaar
        Times Internet


*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int l=0, r=arr.size()-1;
        
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(arr[mid]==key) return mid;
            
            if(arr[mid] >= arr[l]) {
                if(key >= arr[l] && key <= arr[mid]) r=mid-1;
                else l=mid+1;
            } else {
                if(key >= arr[mid] && key <= arr[r]) l=mid+1;
                else r=mid-1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends