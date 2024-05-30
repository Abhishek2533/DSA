int findDuplicate(vector<int> &arr)
{
    int ans = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        ans = ans ^ arr[i];
    }
    for (int i = 1; i < arr.size(); i++)
    {
        ans = ans ^ i;
    }
    return ans;
}



/**************************************************************/



int findDuplicate(vector<int> &arr)
{
    sort(arr.begin(), arr.end());

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] == arr[i - 1])
        {
            return arr[i]; // Found the duplicate
        }
    }

    return -1; // No duplicate found
}
