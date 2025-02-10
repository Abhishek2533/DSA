/*

Company Tags:

        Paytm
        Morgan Stanley
        Amazon
        MakeMyTrip


*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        unordered_map<int, int> mpp;
        int sum=0, len=0;
        
        for(int i=0; i<arr.size(); i++) {
            sum+=(arr[i]==0)?-1:1;
            if(sum==0) len=i+1;
            else if(mpp.find(sum)!=mpp.end()) len=max(len, i-mpp[sum]);
            else mpp[sum]=i;
        }
        return len;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends