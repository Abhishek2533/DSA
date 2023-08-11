#include <bits/stdc++.h>
void solve(string &str, vector<string> &ans, int index)
{
    // base condition
    if (index == str.length())
    {
        ans.push_back(str);
        return;
    }

    for (int j = index; j < str.length(); j++)
    {
        swap(str[index], str[j]);
        solve(str, ans, index + 1);

        // backtrack
        swap(str[index], str[j]);
    }
}

vector<string> generatePermutations(string &str)
{
    vector<string> ans;
    int index = 0;
    solve(str, ans, index);
    // return ans;
    /*         vector<string> ans;
            do{
                ans.push_back(str);
            }while(next_permutation(str.begin(),str.end())); */
    sort(ans.begin(), ans.end());
    return ans;
}