//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to reverse words in a given string.
    string reverseWords(string str)
    {
        // code here
        reverse(str.begin(), str.end());
        int i = 0, j = 0;
        while (j < str.size())
        {
            while (j < str.size() && str[j] != '.')
            {
                j++;
            }
            reverse(str.begin() + i, str.begin() + j);
            j++;
            i = j;
        }
        return str;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends