//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the smallest window in the string s consisting
    // of all the characters of string p.
    string smallestWindow(string s, string p)
    {
        // Your code here
        if (p.length() > s.length())
            return "-1";

        unordered_map<char, bool> mpp;
        int p_hash[26] = {0};

        for (int i = 0; i < p.size(); i++)
        {
            p_hash[p[i] - 'a']++;
            mpp[p[i]] = true;
        }

        int count = mpp.size();
        int startindex = -1;
        int length = 0;
        int minlength = INT_MAX;
        int i = 0, j = 0;

        while (j < s.size())
        {
            if (mpp[s[j]] == true)
            {
                p_hash[s[j] - 'a']--;
                if (p_hash[s[j] - 'a'] == 0)
                {
                    count--;
                }
            }

            while (count == 0)
            {
                length = j - i + 1;
                if (length < minlength)
                {
                    startindex = i;
                    minlength = length;
                }

                if (mpp[s[i]] == true)
                {
                    p_hash[s[i] - 'a']++;
                    if (p_hash[s[i] - 'a'] > 0)
                    {
                        count++;
                    }
                }
                i++;
            }
            j++;
        }

        if (startindex == -1)
            return "-1";
        else
            return s.substr(startindex, minlength);
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
        string pat;
        cin >> pat;
        Solution obj;
        cout << obj.smallestWindow(s, pat) << endl;
    }
    return 0;
}
// } Driver Code Ends