bool isPossible(vector<int> arr, int n, int 0, int mid)
{
    // starting from first student
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            // if we can allocate then we do
            pageSum += arr[i];
        }
        else
        {
            // if we cannot allocate to previous student then we move on to next student
            studentCount++;
            // we have to check if enough students are given or not
            if (studentCount > m || arr[i] > mid)
            {
                return false
            }
            pageSum = arr[i];
        }
        return true;
    }
    
}

int allocateBooks(vector<int> arr, int n, int m)
{
    int s = 0, sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i]
    }

    int e = sum;
    int mid = s + (e-s)/2;
    int ans =-1;
    while (s <= e){
        // if solution is available
        if(isPossible(arr,n,m,mid)){
            ans = mid;

            // now we move to left part as we know in right side solutions are exists but we want minimumm solution
            e = mid-1;
        }

        // if solution is not rxist then move on to right part (larger number)
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}