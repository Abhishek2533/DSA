/*

Company Tags:

        Accolite
        Amazon
        Samsung
        Snapdeal


 */


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
        int num=1;
        sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size(); i++) {
            if(arr[i]<=0) continue;
            else if(i>0 && arr[i] == arr[i-1]) continue;
            else if(arr[i]==num) {
                num++;
            } else break;
        }
        return num;
    }
};

//{ Driver Code Starts.

// int missingNumber(int arr[], int n);

int main() {

    // taking testcases
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
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends