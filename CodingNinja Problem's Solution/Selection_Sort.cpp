void selesctionSort(vector<int>& arr, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        minIndex = i;

        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
    
}