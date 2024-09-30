//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int subStringCount(string s)
    {
        unordered_map<char, int> temp;
        int count = 1;

        for (char c : s)
        {
            int newCount = 2 * count;

            if (temp.find(c) != temp.end())
                newCount -= temp[c];

            temp[c] = count;
            count = newCount;
        }

        return count;
    }
    string betterString(string str1, string str2)
    {
        // code here
        int count1 = subStringCount(str1);
        int count2 = subStringCount(str2);

        return count2 > count1 ? str2 : str1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends