/*

Company Tags:

        Flipkart
        Microsoft


*/




// METHOD 1:

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int i=0, j=0;
        while(i<a.size() && j<b.size()) {
            if(a[i]<=b[j]) {
                if(k==1) return a[i];
                else i++;
            } else {
                if(k==1) return b[j];
                else j++;
            }
            k--;
        }
        
        while(i<a.size() && j>=b.size()) {
            if(k==1) return a[i];
            else i++;
            k--;
        }
        while(j<b.size() && i>=a.size()) {
            if(k==1) return b[j];
            else j++;
            k--;
        }
        return 0;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
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
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n1=a.size(), n2=b.size();
        int n=n1+n2;
        if(n1>n2) return kthElement(b, a, k);

        int low=max(0, k-n2), high=min(k, n1);

        while(low<=high) {
            int mid1=(low+high)>>1;
            int mid2=k-mid1;
            
            int l1 = (mid1 > 0) ? a[mid1 - 1] : INT_MIN;
            int l2 = (mid2 > 0) ? b[mid2 - 1] : INT_MIN;
            int r1 = (mid1 < n1) ? a[mid1] : INT_MAX;
            int r2 = (mid2 < n2) ? b[mid2] : INT_MAX;

            if(l1<=r2 && l2<=r1) {
                return max(l1, l2);
            } else if(l1>r2) high=mid1-1;
            else low=mid1+1;
        }
        return 0;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends