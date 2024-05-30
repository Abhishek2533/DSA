long long maxSubarraySum(vector<int> arr, int n)
{
    // Write your code here.
    long long maxsum = 0;
    long long currsum = 0;
    for(int i=0; i<n; i++){
        currsum +=arr[i];
        if(currsum > maxsum){
            maxsum = currsum;
        }
        if(currsum<0){
            currsum = 0;
        }
    }
    return maxsum;
}