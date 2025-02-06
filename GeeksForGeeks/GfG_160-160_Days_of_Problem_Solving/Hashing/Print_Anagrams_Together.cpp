/*

Company Tags:

        Morgan Stanley
        Amazon
        Microsoft
        Snapdeal
        D-E-Shaw
        Goldman Sachs


*/




// METHID 1:

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        vector<vector<string>> res;
        unordered_map<string, int> mpp;
        
        for(int i=0; i<arr.size(); i++) {
            string s=arr[i];
            
            sort(s.begin(), s.end());
            
            if(mpp.find(s) == mpp.end()) {
                mpp[s]=res.size();
                res.push_back({});
            }
            
            res[mpp[s]].push_back(arr[i]);
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends








// METHOD 2:

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string hashedString(string& s) {
        string hash;
        vector<int> freq(26, 0);
        
        for(char c : s) freq[c-'a']+=1;
        
        for(int i=0; i<26; i++) {
            hash.append(to_string(freq[i]));
            hash.append("$");
        }
        
        return hash;
    }
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        vector<vector<string>> res;
        unordered_map<string, int> mpp;
        
        for(int i=0; i<arr.size(); i++) {
            string s=hashedString(arr[i]);
            
            if(mpp.find(s) == mpp.end()) {
                mpp[s]=res.size();
                res.push_back({});
            }
            
            res[mpp[s]].push_back(arr[i]);
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends