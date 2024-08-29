//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Driver program to test above function

// } Driver Code Ends
class Solution
{
public:
    /*you are required to complete this method*/
    int convertFive(int n)
    {
        // Your code here
        int num = 0;
        int d = 1;
        while (n)
        {
            int a = n % 10;
            if (a == 0)
                a = 5;
            num = a * d + num;
            d *= 10;
            n /= 10;
        }
        return num;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.convertFive(n) << endl;
    }
}
// } Driver Code Ends