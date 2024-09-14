//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    void rearrange(vector<int> &arr)
    {
        // code here

        vector<int> pos;
        vector<int> neg;

        for (int num : arr)
        {
            if (num >= 0)
                pos.push_back(num);
            else
                neg.push_back(num);
        }

        int i = 0, posIndex = 0, negIndex = 0;
        bool flag = true;

        while (posIndex < pos.size() && negIndex < neg.size())
        {
            if (flag)
            {
                arr[i++] = pos[posIndex++];
            }
            else
            {
                arr[i++] = neg[negIndex++];
            }
            flag = !flag;
        }

        while (posIndex < pos.size())
        {
            arr[i++] = pos[posIndex++];
        }

        while (negIndex < neg.size())
        {
            arr[i++] = neg[negIndex++];
        }
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
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num)
        {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends