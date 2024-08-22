//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int convertFive(int n);

// } Driver Code Ends
/*you are required to complete this method*/
class Solution
{
public:
    int convertFive(int n)
    {
        // Your code here
        string temp = to_string(n);
        string v;
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i] - '0' == 0)
                v.push_back('5');
            else
                v.push_back(temp[i]);
        }
        int ans = stoi(v);
        return ans;
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
        Solution ob;
        cout << ob.convertFive(n) << endl;
    }
}
// } Driver Code Ends