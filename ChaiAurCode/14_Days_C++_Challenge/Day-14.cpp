/*

Problem Statement

You are tasked with designing an efficient system to answer multiple range sum queries over an array. The array contains integers, and you need to compute the sum of elements in a given subarray efficiently.
Given an array ( A ) of size ( n ), you need to process ( q ) queries, each asking for the sum of elements from index ( l ) to ( r ) (both inclusive). The naive approach of iterating over the subarray for each query would be inefficient, especially for large arrays.


Input Format

1. An integer ( n ) representing the size of the array.
2. An array ( A ) of ( n ) integers.
3. An integer ( q ) representing the number of queries.
4. ( q ) queries, each consisting of two integers ( l ) and ( r ), where:
    ( l ): The starting index of the subarray (1-based index).
    ( r ): The ending index of the subarray (1-based index).


Output Format

For each query, return the sum of elements from index ( l ) to ( r ) (both inclusive).


Constraints

1. 1<=n<=10^5
2. 1<=[i]<=10^6
3. 1<=q<=10^5
4. 1<=l<=r<=n
5. The array indices are 1-based.


Example 1

Input:
5 1 2 3 4 5 3 1 3 2 4 3 5
Output:
6 9 12

Explanation:
    Query1: Sum of elements from index 1 to 3 is (1+2+3=6)
    Query2: Sum of elements from index 2 to 4 is (2+3+4=9)
    Query2: Sum of elements from index 3 to 5 is (3+4+5=12)


Example 2

Input:
4 10 20 30 40 2 1 2 2 4
Output:
30 90


*/


// SOURCE CODE


#include <iostream>
#include <vector>
using namespace std;

// Function to process the range sum queries using prefix sums
vector<int> sol(int n, vector<int>& A, int q, vector<pair<int, int>>& queries) {
    // Step 1: Create the prefix sum array
    vector<long long> prefixSum(n + 1, 0);  // prefixSum[0] = 0 by default, which is correct for 1-based indexing.
    
    // Calculate prefix sums
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + A[i];
    }

    // Step 2: Process each query
    vector<int> result;
    for (int i = 0; i < q; i++) {
        int l = queries[i].first;
        int r = queries[i].second;
        // The sum from A[l] to A[r] is prefixSum[r] - prefixSum[l-1]
        result.push_back(prefixSum[r] - prefixSum[l - 1]);
    }

    return result;
}

int main() {
    int n, q;
    cin >> n;

    vector<int> A(n + 1, 0);  // 1-based indexing, so size is n+1
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    cin >> q;
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        queries[i] = {l, r};
    }

    // Call the sol function to process the queries
    vector<int> result = sol(n, A, q, queries);

    // Output the results
    for (int i = 0; i < result.size(); i++) {
        if (i == result.size() - 1) {
            cout << result[i];
        } else {
            cout << result[i] << " ";
        }
    }

    return 0;
}