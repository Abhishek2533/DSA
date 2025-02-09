/*

Company Tags:

        Accolite
        Amazon
        Microsoft


*/





// METHOD 1:

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        vector<int> res;
        
        for(int i=0; i<=arr.size()-k; i++) {
            unordered_set<int> st;
            for(int j=i; j<i+k; j++) {
                st.insert(arr[j]);
            }
            res.push_back(st.size());
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends











// METHOD 2:

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        vector<int> res;
        unordered_map<int, int> mpp;
        
        for(int i=0; i<k; i++) mpp[arr[i]]+=1;
        res.push_back(mpp.size());
        
        for(int i=k; i<arr.size(); i++) {
            mpp[arr[i]]+=1;
            mpp[arr[i-k]]-=1;
            
            if(mpp[arr[i-k]]==0) mpp.erase(arr[i-k]);
            
            res.push_back(mpp.size());
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends