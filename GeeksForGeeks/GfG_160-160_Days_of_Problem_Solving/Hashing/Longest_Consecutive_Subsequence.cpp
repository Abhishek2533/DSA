/*

Company Tags:

        Amazon
        Microsoft
        Walmart


*/

// METHOD 1:

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        sort(arr.begin(), arr.end());
        int ans=1, cnt=1;
        
        for(int i=1; i<arr.size(); i++) {
            if(arr[i]==arr[i-1]) continue;
            if(arr[i]==arr[i-1]+1) cnt++;
            else cnt=1;
            
            ans=max(ans, cnt);
        }
        
        return ans;
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
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
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

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        unordered_set<int> st;
        int ans=0;
        
        for(int num : arr) st.insert(num);
        
        for(int num : arr) {
            if(st.find(num) != st.end() && st.find(num-1) == st.end()) {
                int curr = num;
                int cnt=0;
                
                while(st.find(curr) != st.end()) {
                    st.erase(curr);
                    curr++, cnt++;
                }
                
                ans=max(ans, cnt);
            }
        }
        
        return ans;
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
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends