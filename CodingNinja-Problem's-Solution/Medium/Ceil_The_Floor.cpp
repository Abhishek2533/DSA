pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
    // Write your code here.

    int low1 = 0;
    int high1 = n - 1;
    int low2 = 0;
    int high2 = n - 1;
    int floor = -1;
    int ceil = -1;

    // floor
    while (low1 <= high1)
    {
        int mid = low1 + (high1 - low1) / 2;
        if (a[mid] <= x)
        {
            floor = a[mid];
            low1 = mid + 1;
        }
        else
            high1 = mid - 1;
    }

    // ceil
    while (low2 <= high2)
    {
        int mid = low2 + (high2 - low2) / 2;
        if (a[mid] >= x)
        {
            ceil = a[mid];
            high2 = mid - 1;
        }
        else
            low2 = mid + 1;
    }

    return {floor, ceil};
}