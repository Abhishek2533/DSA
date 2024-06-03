// SOLUTION 1:

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    vector<long long> factorialNumbers(long long N)
    {
        // Write Your Code here
        long long sum = 1;
        int i = 1;
        vector<long long> res;
        while (sum <= N)
        {
            sum = sum * (i++);
            if (sum <= N)
                res.emplace_back(sum);
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin >> N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for (auto num : ans)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

// SOLUTION 2:

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    long long fact(int n)
    {
        if (n == 1 || n == 0)
            return 1;
        return n * fact(n - 1);
    }
    vector<long long> factorialNumbers(long long N)
    {
        // Write Your Code here
        long long factVal = 1;
        int i = 1;
        vector<long long> res;
        while (i <= N)
        {
            factVal = fact(i);
            if (factVal > N)
                break;
            res.emplace_back(factVal);
            i++;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin >> N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for (auto num : ans)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends