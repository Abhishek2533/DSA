#include<bits/stdc++.h>
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    int index1 = lower_bound(arr.begin(), arr.end(), k)-arr.begin();
    int index2 = upper_bound(arr.begin(), arr.end(), k)-arr.begin();
    if(index1 != index2)  return {index1, index2-1};
    return {-1, -1};
}