// BRUTE FORCE 

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        // code here

        unordered_map<int, int> mpp;
        int repeating, missing;

        for (int i = 0; i < arr.size(); i++)
        {
            mpp[arr[i]]++;
        }

        for (int i = 1; i <= arr.size(); i++)
        {
            if (mpp[i] == 2)
            {
                repeating = i;
            }
            else if (mpp[i] == 0)
            {
                missing = i;
            }
        }

        return {repeating, missing};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends








// OPTIMIZE CODE

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        long long sum = 0, sum_sq = 0;
        long long expected_sum = (long long)n * (n + 1) / 2;
        long long expected_sum_sq = (long long)n * (n + 1) * (2 * n + 1) / 6;

        // Calculate the sum and sum of squares for the array
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            sum_sq += (long long)arr[i] * arr[i];
        }

        // Difference between the expected sum and actual sum
        long long diff_sum = expected_sum - sum; // (missing - repeating)

        // Difference between the expected square sum and actual square sum
        long long diff_sum_sq = expected_sum_sq - sum_sq; // (missing^2 - repeating^2)

        // Solving the two equations:
        // diff_sum_sq = (missing^2 - repeating^2) = (missing - repeating) * (missing + repeating)
        // diff_sum = (missing - repeating)

        // From the above, we can find (missing + repeating)
        long long sum_miss_rep = diff_sum_sq / diff_sum; // (missing + repeating)

        // Now we have:
        // missing - repeating = diff_sum
        // missing + repeating = sum_miss_rep

        // Solving these two equations:
        int missing = (diff_sum + sum_miss_rep) / 2;
        int repeating = sum_miss_rep - missing;

        return {repeating, missing};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends









// MOST OPTIMAL CODE - USING XOR

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        int xor_total = 0;
        
        // Step 1: XOR all the array elements and numbers from 1 to n
        for (int i = 0; i < n; i++) {
            xor_total ^= arr[i];       // XOR elements of the array
            xor_total ^= (i + 1);      // XOR numbers from 1 to n
        }

        // Step 2: Find the rightmost set bit in xor_total (i.e., missing ^ repeating)
        int rightmost_set_bit = xor_total & ~(xor_total - 1);

        // Initialize two buckets for partitioning numbers
        int bucket1 = 0, bucket2 = 0;

        // Step 3: Partition the elements and numbers from 1 to n
        for (int i = 0; i < n; i++) {
            // Partition the array elements
            if (arr[i] & rightmost_set_bit) {
                bucket1 ^= arr[i];
            } else {
                bucket2 ^= arr[i];
            }
            
            // Partition the numbers from 1 to n
            if ((i + 1) & rightmost_set_bit) {
                bucket1 ^= (i + 1);
            } else {
                bucket2 ^= (i + 1);
            }
        }

        // Now bucket1 and bucket2 hold the two numbers: one is missing, the other is repeating.
        // Step 4: Identify which is missing and which is repeating
        for (int i = 0; i < n; i++) {
            if (arr[i] == bucket1) {
                // If bucket1 is found in the array, it is the repeating number
                return {bucket1, bucket2};
            }
        }

        // Otherwise, bucket2 is the repeating number
        return {bucket2, bucket1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends