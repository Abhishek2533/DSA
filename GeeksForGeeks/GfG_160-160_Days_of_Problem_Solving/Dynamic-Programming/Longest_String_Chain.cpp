// METHOD 1: RECURSION

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool isPredecessor(string &w, string &currStr)
    {
        if (w.size() + 1 != currStr.size())
            return false;
        int i = 0, j = 0;
        bool skipped = false;
        while (i < w.size() && j < currStr.size())
        {
            if (w[i] == currStr[j])
            {
                i++, j++;
            }
            else
            {
                if (skipped)
                    return false;
                skipped = true;
                j++;
            }
        }
        return true;
    }
    int findChain(vector<string> &words, string &currStr)
    {
        int maxLen = 1;
        for (string &w : words)
        {
            if (isPredecessor(w, currStr))
            {
                maxLen = max(maxLen, 1 + findChain(words, w));
            }
        }

        return maxLen;
    }
    int longestStringChain(vector<string> &words)
    {
        // Code here
        int res = 1;

        for (string &w : words)
        {
            res = max(res, findChain(words, w));
        }

        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number)
        {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends












// METHOD 2: TABULATION

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool isPredecessor(string &w, string &currStr)
    {
        if (w.size() + 1 != currStr.size())
            return false;
        int i = 0, j = 0;
        bool skipped = false;
        while (i < w.size() && j < currStr.size())
        {
            if (w[i] == currStr[j])
            {
                i++, j++;
            }
            else
            {
                if (skipped)
                    return false;
                skipped = true;
                j++;
            }
        }
        return true;
    }

    int longestStringChain(vector<string> &words)
    {
        // Code here
        int res = 1;
        vector<int> dp(words.size(), 1);
        // sort words based on length
        sort(words.begin(), words.end(), [](const string &a, const string &b)
             { return a.size() < b.size(); });

        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (isPredecessor(words[j], words[i]))
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            res = max(res, dp[i]);
        }

        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number)
        {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends