/*

Company Tags:

        Flipkart
        Amazon
        Microsoft
        Snapdeal
        D-E-Shaw
        FactSet
        Walmart
        Goldman Sachs
        SAP Labs
        Sapient
        One97
        GreyOrange
        Kuliza


*/



// METHOD 1: TC -> O(1) | SC -> O(N) + O(N)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    private: stack<int> st1, st2;
    public:
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        if(st1.empty()) {
            st1.push(x);
            st2.push(x);
        } else {
            st1.push(x);
            st2.push(min(x, st2.top()));
        }
    }
    
    // Remove the top element from the Stack
    void pop() {
        // code here
        if(!st1.empty() && !st2.empty()) {
            st1.pop();
            st2.pop();
        }
    }
    
    // Returns top element of the Stack
    int peek() {
        // code here
        if(!st1.empty()) return st1.top();
        return -1;
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(!st2.empty()) return st2.top();
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;
        
        Solution ob;
        
        while (q--) {
            int qt;
            cin >> qt;
            
            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    
    return 0;
}

// } Driver Code Ends






// METHOD 2: TC -> O(1) | SC -> O(N)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private: stack<pair<int, int>> st;
  public:
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        if(!st.empty()) {
            st.push({x, min(x, st.top().second)});
        } else {
            st.push({x, x});
        }
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(!st.empty()) st.pop();
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        if(!st.empty()) return st.top().first;
        return -1;
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(!st.empty()) return st.top().second;
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends