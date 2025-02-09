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
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // code here
        int count=0;
        for(int i=0; i<arr.size()-2; i++) {
            for(int j=i+1; j<arr.size()-1; j++) {
                for(int k=j+1; k<arr.size(); k++) {
                    if(arr[i]+arr[j]>arr[k] && arr[i]+arr[k]>arr[j] && arr[j]+arr[k]>arr[i]) count++;
                }
            }
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.countTriangles(a) << "\n~\n";
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
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // code here
        int count=0;
        sort(arr.begin(), arr.end());
        
        for(int i=0; i<arr.size()-2; i++) {
            for(int j=i+1; j<arr.size()-1; j++) {
                int k = lower_bound(arr.begin()+j+1, arr.end(), arr[i]+arr[j]) - arr.begin();
                count+=(k-j-1);
            }
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.countTriangles(a) << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends










// METHOD 3:

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // code here
        int count=0;
        sort(arr.begin(), arr.end());
        
        for(int i=2; i<arr.size(); i++) {
            int l=0, r=i-1;
            while(l<r) {
                if(arr[l]+arr[r]>arr[i]) {
                    count+=r-l;
                    r--;
                } else l++;
            }
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.countTriangles(a) << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends