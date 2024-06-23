//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // n: input to count the number of set bits
    // Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        long cnt = 0;
        int x = 0; // x represents the current bit position (0, 1, 2, ...)

        while ((1 << x) <= n)
        {
            // Calculate the number of complete blocks of size 2^(x+1)
            int completeBlocks = (n + 1) / (1 << (x + 1));
            cnt += completeBlocks * (1 << x);

            // Calculate the remaining set bits in the partial block
            int remainder = (n + 1) % (1 << (x + 1));
            if (remainder > (1 << x))
            {
                cnt += remainder - (1 << x);
            }

            x++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {
        int n;
        cin >> n; // input n
        Solution ob;
        cout << ob.countSetBits(n) << endl; // print the answer
    }
    return 0;
}

// } Driver Code Ends