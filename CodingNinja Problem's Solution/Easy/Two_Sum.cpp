#include <bits/stdc++.h>
#include <vector>

vector<pair<int, int>> twoSum(vector<int> &arr, int target, int n)
{
    vector<pair<int, int>> ans;
    int s = 0, e = n - 1;

    sort(arr.begin(), arr.end());

    while (s < e)
    {

        if (arr[s] + arr[e] == target)
        {
            ans.push_back({arr[s++], arr[e--]});
        }
        else if (arr[s] + arr[e] < target)
        {
            s++;
        }
        else
        {
            e--;
        }
    }

    if (ans.empty())
        ans.push_back(make_pair(-1, -1));
    return ans;
}
