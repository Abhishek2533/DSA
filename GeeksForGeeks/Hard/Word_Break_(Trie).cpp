//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

struct TrieNode
{
    TrieNode *children[26];
    bool wordEnd;

    TrieNode()
    {
        wordEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(const string &word)
    {
        TrieNode *curr = root;
        for (char c : word)
        {
            if (curr->children[c - 'a'] == NULL)
            {
                TrieNode *newNode = new TrieNode();
                curr->children[c - 'a'] = newNode;
            }
            curr = curr->children[c - 'a'];
        }
        curr->wordEnd = true;
    }

    bool search(const string &s, int start, int end)
    {
        TrieNode *curr = root;
        for (int i = start; i < end; i++)
        {
            if (curr->children[s[i] - 'a'] == NULL)
                return false;
            curr = curr->children[s[i] - 'a'];
        }
        return curr->wordEnd;
    }

    bool helper(const string &word, int start)
    {
        if (start == word.size())
            return true;

        for (int end = start + 1; end <= word.size(); end++)
        {
            if (search(word, start, end) && helper(word, end))
                return true;
        }
        return false;
    }
};

class Solution
{
public:
    // A : given string to search
    // B : vector of available strings

    int wordBreak(string A, vector<string> &B)
    {
        // code here
        Trie trie;
        for (const string &word : B)
            trie.insert(word);

        return trie.helper(A, 0) ? 1 : 0;
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
        vector<string> dict;
        for (int i = 0; i < n; i++)
        {
            string S;
            cin >> S;
            dict.push_back(S);
        }
        string line;
        cin >> line;
        Solution ob;
        cout << ob.wordBreak(line, dict) << "\n";
    }
}

// } Driver Code Ends