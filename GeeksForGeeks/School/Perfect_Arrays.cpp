//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool isPerfect(vector<int> &arr)
    {
        // code here
        int s = 0, e = arr.size() - 1;
        while (s <= e)
        {
            if (arr[s] == arr[e])
            {
                s++;
                e--;
            }
            else
                return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main()
{
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--)
    {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num)
        {
            nums.push_back(num);
        }

        Solution obj;
        bool res = obj.isPerfect(nums);

        if (res)
            cout << "PERFECT" << endl;
        else
            cout << "NOT PERFECT" << endl;
    }
}

// } Driver Code Ends