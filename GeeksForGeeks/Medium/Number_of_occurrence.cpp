//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    /* if x is present in arr[] then returns the count
        of occurrences of x, otherwise returns 0. */
    int count(int arr[], int n, int x)
    {
        // code here
        vector<int> ans{-1, -1};
        int start = 0;
        int end = n - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] == x)
            {
                ans[0] = mid;
                end = mid - 1;
            }
            else if (x > arr[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        if (ans[0] == -1)
        {
            return 0;
        }

        end = n - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] == x)
            {
                ans[1] = mid;
                start = mid + 1;
            }
            else if (x > arr[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        int occ = ans[1] - ans[0] + 1;
        return occ;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends