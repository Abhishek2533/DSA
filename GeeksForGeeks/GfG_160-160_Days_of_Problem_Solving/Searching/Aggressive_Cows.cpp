// METHOD 1:

//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool canPlace(vector<int>& stalls, int dist, int k) {
        int count=1;
        int last=stalls[0];
        
        for(int i=1; i<stalls.size(); i++) {
            if(stalls[i]-last>=dist) {
                last=stalls[i];
                count++;
            }
        }
        
        return count>=k;
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(), stalls.end());
        int res=0;
        int minDist=1, maxDist=stalls.back()-stalls[0];
        
        for(int i=minDist; i<=maxDist; i++) {
            if(canPlace(stalls, i, k)) res=i;
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends









// METHOD 2:

//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool canPlace(vector<int>& stalls, int dist, int k) {
        int count=1;
        int last=stalls[0];
        
        for(int i=1; i<stalls.size(); i++) {
            if(stalls[i]-last>=dist) {
                last=stalls[i];
                count++;
            }
        }
        
        return count>=k;
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(), stalls.end());
        int res=0;
        int low=1, high=stalls.back()-stalls[0];
        
        while(low<=high) {
            int mid=(low+high)/2;
            if(canPlace(stalls, mid, k)) {
                res=mid;
                low=mid+1;
            } else high=mid-1;
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends