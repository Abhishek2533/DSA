/*

Company Tags:

            Infosys
            Flipkart
            Amazon
            Microsoft
            FactSet
            Hike
            MakeMyTrip
            Google
            Qualcomm
            Salesforce


*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int pivot=-1;
        
        for(int i=arr.size()-2; i>=0; i--) {
            if(arr[i]<arr[i+1]) {
                pivot=i;
                break;
            }
        }
        
        if(pivot==-1) reverse(arr.begin(), arr.end());
        else {
            for(int i=arr.size()-1; i>=0; i--) {
                if(arr[i]>arr[pivot]) {
                    swap(arr[i],arr[pivot]);
                    break;
                }
            }
            reverse(arr.begin()+pivot+1, arr.end());
        }
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
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends