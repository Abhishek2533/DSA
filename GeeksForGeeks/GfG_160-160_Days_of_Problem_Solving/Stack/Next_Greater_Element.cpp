/*

Company Tags:

        Flipkart
        Amazon
        Microsoft
        MakeMyTrip
        Adobe


*/



// WAY 1: LONG CODE

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
        public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> res(n, -1);
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int i=n-1;
        while(i>=0) {
            if(pq.empty()) {
                pq.push(arr[i]);
                i--;
            } else {
                if(arr[i]<pq.top()) {
                    res[i]=pq.top();
                    pq.push(arr[i]);
                    i--;
                } else pq.pop();
            }
        }
        
        return res;
}
};


//{ Driver Code Starts.

int main() {
        int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after reading t
    while (t--) {
        vector<int> a;
        string input;

        // Reading the entire input line for the array
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> result = obj.nextLargerElement(a);
        
        // Print the result in the required format
        for (int i = 0; i < result.size(); i++) {
                if (i != 0)
                cout << " ";
                cout << result[i];
        }
        cout << endl;        // Ensure new line after each test case output
        cout << "~" << endl; // Ensure new line after each test case output
    }
    
    return 0;
}

// } Driver Code Ends






// WAY 2: SHORT CODE

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> res(n, -1);
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=n-1; i>=0; i--) {
            while(!pq.empty() && arr[i]>=pq.top()) pq.pop();
            if(!pq.empty()) res[i]=pq.top();
            pq.push(arr[i]);
        }
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after reading t
    while (t--) {
        vector<int> a;
        string input;

        // Reading the entire input line for the array
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> result = obj.nextLargerElement(a);

        // Print the result in the required format
        for (int i = 0; i < result.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
        cout << endl;        // Ensure new line after each test case output
        cout << "~" << endl; // Ensure new line after each test case output
    }

    return 0;
}

// } Driver Code Ends