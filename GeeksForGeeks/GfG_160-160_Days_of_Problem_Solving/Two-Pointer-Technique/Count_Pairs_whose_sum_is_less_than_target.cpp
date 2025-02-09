// METHOD 1:

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
        int count=0;
        for(int i=0; i<arr.size()-1; i++) {
            for(int j=i+1; j<arr.size(); j++) {
                 if(arr[i]+arr[j] < target) count++;
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
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends










// METHOD 2:

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int binarySearch(vector<int>& arr, int num) {
        int cnt=arr.size();
        int l=0, r=arr.size()-1;
        
        while(l<=r) {
            int mid=l+(r-l)/2;
            
            if(arr[mid]>=num) {
                cnt=mid;
                r=mid-1;
            } else l=mid+1;
        }
        
        return cnt;
    }
    
    int countPairs(vector<int> &arr, int target) {
        // Your code here
        int count=0;
        sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size(); i++) {
            int rem=target-arr[i];
            int num=binarySearch(arr, rem);
            
            count+=num;
            if(num>i) count--;
        }
        
        return count/2;
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
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends









// METHOD 3:

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
        int count=0;
        sort(arr.begin(), arr.end());
        
        int l=0, r=arr.size()-1;
        
        while(l<r) {
            int sum = arr[l]+arr[r];
            
            if(sum<target) {
                count+=r-l;
                l++;
            } else r--;
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
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends