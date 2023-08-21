vector<int> rotateArray(vector<int> arr, int k)
{
    vector<int> ans;
    int n = arr.size();
    int temp[k];

    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[i];
    }

    for (int i = 0; i < n - k; i++)
    {
        arr[i] = arr[i + k];
    }

    for (int i = n - k; i < n; i++)
    {
        arr[i] = temp[i - n + k];
    }

    for (int i = 0; i < n; i++)
    {
        ans.push_back(arr[i]);
    }

    return ans;
}
