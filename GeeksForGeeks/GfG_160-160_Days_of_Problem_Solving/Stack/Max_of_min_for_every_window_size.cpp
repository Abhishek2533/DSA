/*

Company Tags:

        Flipkart
        Amazon
        Microsoft


*/



// BRUTE FORCE: TC -> O(N^3) | SC -> O(1)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        vector<int> res(n, 0);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n-i; j++) {
                int num = INT_MAX;
                for(int k=j; k<i+j+1; k++) {
                    num=min(num, arr[k]);
                }
                
                res[i]=max(res[i], num);
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
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
        cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends






// OPTIMAL APPROACH: TC -> O(N) | SC -> O(N)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        vector<int> res(n, 0);
        stack<int> st;
        
        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[st.top()]>arr[i]) {
                int index=st.top();
                st.pop();
                int range = st.empty() ? i : i-st.top()-1;
                res[range-1]=max(res[range-1], arr[index]);
            }
            
            st.push(i);
        }
        
        while(!st.empty()) {
            int index=st.top();
            st.pop();
            int range = st.empty() ? n : n-st.top()-1;
            res[range-1]=max(res[range-1], arr[index]);
        }
        
        for(int i=n-2; i>=0; i--) {
            res[i] = max(res[i], res[i+1]);
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
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends