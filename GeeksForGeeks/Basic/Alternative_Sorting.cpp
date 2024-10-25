//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    vector<int> alternateSort(vector<int>& arr) {
        // Your code goes here
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        bool flag=1;
        int x=0, y=arr.size()-1;
        for(int i=0; i<arr.size(); i++) {
            if(flag) {
                arr[i] = temp[y];
                y--;
                flag = !flag;
            } else {
                arr[i] = temp[x];
                x++;
                flag = !flag;
            };
        }
        return arr;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.alternateSort(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends







// METHOD - 2

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    vector<int> alternateSort(vector<int>& arr) {
        // Your code goes here
        sort(arr.begin(), arr.end());
        vector<int> temp;
        bool flag=1;
        int i=0, j=arr.size()-1;
        
        while(i<=j) {
            if(flag) {
                temp.push_back(arr[j]);
                flag = !flag;
                j--;
            } else {
                temp.push_back(arr[i]);
                flag = !flag;
                i++;
            }
        }
        return temp;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.alternateSort(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends