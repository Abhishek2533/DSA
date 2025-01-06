/* Company Tags

SAPLabs
Rockstand

*/



// METHOD 1: TC -> O(n*logn) || SC -> O(1)

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
    
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        sort(arr.begin(), arr.end());
        
        for(int i=arr.size()-2; i>=0; i--) {
            if(arr[i]!=arr[arr.size()-1]) return arr[i];
        }
        return -1;
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
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends





// METHOD 2: TC -> O(2N) ~ O(N) || SC -> O(1)

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
    
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int prev=-1, curr=-1;
        
        for(int i=0; i<arr.size(); i++) {
            if(arr[i]>curr) curr=arr[i];
        }
        for(int i=0; i<arr.size(); i++) {
            if(arr[i]<curr && arr[i]>prev) prev=arr[i];
        }
        return prev;
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
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends





// METHOD 3: TC -> O(N) || SC -> O(1)

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
    
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int prev=-1, curr=-1;
        
        for(int i=0; i<arr.size(); i++) {
            if(arr[i]>curr) {
                prev=curr;
                curr=arr[i];
            }
        
            else if(arr[i]<curr && arr[i]>prev) prev=arr[i];
        }
        return prev;
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
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends