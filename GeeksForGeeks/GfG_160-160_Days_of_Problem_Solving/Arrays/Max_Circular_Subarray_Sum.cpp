/*

Company Tags:

        Amazon
        Microsoft


 */




// METHOD 1:

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        // your code here
        int res = arr[0];
        
        for(int i=0; i<arr.size(); i++) {
            int currSum=0;
            for(int j=0; j<arr.size(); j++) {
                int idx=(i+j)%arr.size();
                currSum+=arr[idx];
                res=max(res,currSum);
            }
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
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends







// METHOD 2:

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        // your code here
        int totalSum=0, currMinSum=0, currMaxSum=0, maxSum=arr[0], minSum=arr[0];
        
        for(int i=0; i<arr.size(); i++) {
            currMaxSum=max(currMaxSum+arr[i], arr[i]);
            maxSum=max(maxSum, currMaxSum);
            
            currMinSum=min(currMinSum+arr[i], arr[i]);
            minSum=min(minSum, currMinSum);
            
            totalSum+=arr[i];
        }
        
        int normalSUm=maxSum;
        int circularSum = totalSum-minSum;
        
        if(minSum==totalSum) return normalSUm;
        return max(maxSum, circularSum);
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends