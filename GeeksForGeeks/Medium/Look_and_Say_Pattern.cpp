//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string countAndSay(int n)
    {
        // code here
        string res = "1";
        if (n == 1)
            return res;

        for (int i = 1; i < n; i++)
        {
            int count = 1;
            string temp = "";

            for (int j = 1; j < res.size(); j++)
            {
                if (res[j] == res[j - 1])
                    count++;
                else
                {
                    temp = temp + to_string(count) + res[j - 1];
                    count = 1;
                }
            }
            temp = temp + to_string(count) + res.back();
            res = temp;
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
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends