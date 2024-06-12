class Solution
{
public:
    int lenOfLongSubarr(int A[], int N, int K)
    {
        // Complete the function
        int left = 0, right = 0, maxLen = 0;
        long long sum = A[0];
        while (right < N)
        {
            while (left <= right && sum > K)
            {
                sum -= A[left];
                left++;
            }

            if (sum == K)
            {
                maxLen = max(maxLen, right - left + 1);
            }

            right++;
            if (right < N)
                sum += A[right];
        }
        return maxLen;
    }
};