//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n)
    {
        // code here
        long long a = 0;
        long long b = 1;
        vector<long long> v;
        v.push_back(b);
        for (int i = 1; i < n; i++)
        {
            long long c = a + b;
            a = b;
            b = c;
            v.push_back(c);
        }
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking number of elements
        int n;
        cin >> n;
        Solution obj;
        // calling function printFibb()
        vector<long long> ans = obj.printFibb(n);

        // printing the elements of vector
        for (long long i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends