//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution
{
public:
    long long maxSum(vector<int> &arr)
    {
        // code here
        sort(arr.begin(), arr.end());

        long long ans = 0;
        int left = 0, right = arr.size() - 1;
        bool flag = true;

        while (left < right)
        {
            if (flag)
            {
                ans += arr[right] - arr[left];
                left++;
            }
            else
            {
                ans += arr[right] - arr[left];
                right--;
            }

            flag = !flag;
        }

        return ans += arr[left] - arr[0];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--)
    {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num)
        {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends