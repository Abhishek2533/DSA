//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution
{
public:
    // Function to return the count of number of elements in union of two arrays.
    int doUnion(vector<int> arr1, vector<int> arr2)
    {
        // code here
        set<int> s;
        int n1 = arr1.size();
        int n2 = arr2.size();

        int merged_size = n1 + n2;
        int merge_arr[n1 + n2];
        for (int i = 0; i < n1; i++)
        {
            merge_arr[i] = arr1[i];
        }
        for (int i = 0; i < n2; i++)
        {
            merge_arr[n1 + i] = arr2[i];
        }
        for (int i = 0; i < merged_size; i++)
        {
            s.insert(merge_arr[i]);
        }
        return s.size();
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after reading t

    while (t--)
    {
        vector<int> a;
        vector<int> b;

        string input;
        // For a
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            a.push_back(number);
        }

        // For b
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss2(input);
        while (ss2 >> number)
        {
            b.push_back(number);
        }

        Solution ob;
        cout << ob.doUnion(a, b) << endl;
    }

    return 0;
}
// } Driver Code Ends