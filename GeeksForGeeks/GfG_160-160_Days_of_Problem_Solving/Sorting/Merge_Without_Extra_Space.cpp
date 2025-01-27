/*

Company Tags:

        Zoho
        Microsoft
        Snapdeal
        Goldman Sachs
        Adobe
        Linkedin
        Amdocs
        Brocade
        Juniper Networks
        Quikr
        Synopsys


*/


// METHOD 1:

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int left=a.size()-1, right=0;
        while(left>=0 && right<b.size()) {
            if(a[left] > b[right]) {
                swap(a[left], b[right]);
                left--, right++;
            } else if(a[left]<=b[right]) break;
        }
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }
};

//{ Driver Code Starts.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Inputting the test cases

    while (t--) {
        vector<int> a, b;

        // Reading the first array as a space-separated line
        string arr1;
        getline(cin >> ws, arr1); // Use ws to ignore any leading whitespace
        stringstream ss1(arr1);
        int num;
        while (ss1 >> num) {
            a.push_back(num);
        }

        // Reading the second array as a space-separated line
        string arr2;
        getline(cin, arr2);
        stringstream ss2(arr2);
        while (ss2 >> num) {
            b.push_back(num);
        }

        Solution ob;
        ob.mergeArrays(a, b);

        // Output the merged result
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
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
class Solution {
  public:
    void swapVal(vector<int>& a, vector<int>& b, int left, int right) {
        if(a[left]>b[right]) swap(a[left], b[right]);
    }
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int len = a.size()+b.size();
        int gap = len/2 + len%2;
        
        while(gap>0) {
            int left = 0, right=gap;
            while(right < len) {
                if(left<a.size() && right>=a.size()) {
                    swapVal(a, b, left, right-a.size());
                }
                else if(left<a.size() && right<a.size()) {
                    swapVal(a, a, left, right);
                }
                else if(left>=a.size()) {
                    swapVal(b, b, left-a.size(), right-a.size());
                }
                left++, right++;
            }
            
            if(gap==1) break;
            gap = gap/2 + gap%2;
        }
    }
};

//{ Driver Code Starts.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Inputting the test cases

    while (t--) {
        vector<int> a, b;

        // Reading the first array as a space-separated line
        string arr1;
        getline(cin >> ws, arr1); // Use ws to ignore any leading whitespace
        stringstream ss1(arr1);
        int num;
        while (ss1 >> num) {
            a.push_back(num);
        }

        // Reading the second array as a space-separated line
        string arr2;
        getline(cin, arr2);
        stringstream ss2(arr2);
        while (ss2 >> num) {
            b.push_back(num);
        }

        Solution ob;
        ob.mergeArrays(a, b);

        // Output the merged result
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends