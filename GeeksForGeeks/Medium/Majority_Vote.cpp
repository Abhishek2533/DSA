//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int> &nums)
    {
        // Your code goes here.
        int n = nums.size();

        // Step 1: Initialize two potential candidates and their counts
        int cnt1 = 0, ele1 = -1, cnt2 = 0, ele2 = -1;

        // Step 2: Find the two most likely majority candidates
        for (int x : nums)
        {
            // Case 1: Assign a new candidate if cnt1 is 0 and it's not the second candidate
            if (cnt1 == 0 && ele2 != x)
            {
                cnt1 = 1;
                ele1 = x;
            }
            // Case 2: Assign a new candidate if cnt2 is 0 and it's not the first candidate
            else if (cnt2 == 0 && ele1 != x)
            {
                cnt2 = 1;
                ele2 = x;
            }
            // Case 3: Increase count of first candidate if it matches
            else if (ele1 == x)
                ++cnt1;
            // Case 4: Increase count of second candidate if it matches
            else if (ele2 == x)
                ++cnt2;
            // Case 5: If both candidates don't match, decrease both counts
            else
            {
                --cnt1;
                --cnt2;
            }
        }

        // Step 3: Verify if the candidates appear more than n/3 times
        cnt1 = cnt2 = 0;
        for (int x : nums)
        {
            if (ele1 == x)
                ++cnt1; // Count occurrences of the first candidate
            if (ele2 == x)
                ++cnt2; // Count occurrences of the second candidate
        }

        // Step 4: Add candidates to the result if they have more than n/3 votes
        vector<int> ans;
        if (cnt1 > n / 3)
            ans.push_back(ele1);
        if (cnt2 > n / 3)
            ans.push_back(ele2);

        // If no majority element is found, return -1
        if (ans.empty())
            ans.push_back(-1);

        return ans;
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

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num)
        {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends