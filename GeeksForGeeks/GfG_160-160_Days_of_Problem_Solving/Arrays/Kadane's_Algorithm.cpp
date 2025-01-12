/*

Company Tags:

        Zoho
        Flipkart
        Morgan Stanley
        Accolite
        Amazon
        Microsoft
        Samsung
        Snapdeal
        24*7 Innovation Labs
        Citrix
        D-E-Shaw
        FactSet
        Hike
        Housing.com
        MetLife
        Ola Cabs
        Oracle
        Payu
        Teradata
        Visa
        Walmart
        Adobe
        Google
        Arcesium


*/


//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        int sum =arr[0], ans=arr[0];
        for(int i=1; i<arr.size(); i++) {
            sum=max(sum+arr[i], arr[i]);
            ans=max(ans, sum);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
    }
}
// } Driver Code Ends