
// } Driver Code Ends
class Solution
{
public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    int search(int arr[], int start, int end, int K)
    {
        int mid = start + (end - start) / 2;
        if (K == arr[mid])
            return 1;
        if (mid == start || mid == end)
            return -1;
        if (K < arr[mid])
        {
            search(arr, 0, mid, K);
        }
        else if (K > arr[mid])
        {
            search(arr, mid + 1, end, K);
        }
    }

    int searchInSorted(int arr[], int N, int K)
    {

        // Your code here
        // reccursion method
        int mid = N / 2;
        if (K == arr[mid])
            return 1;
        else if (K < arr[mid])
        {
            search(arr, 0, mid, K);
        }
        else
        {
            search(arr, mid + 1, N, K);
        }
    }
};

//{ Driver Code Starts.

int main(void)
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.searchInSorted(arr, n, k) << endl;
    }

    return 0;
}

// } Driver Code Ends