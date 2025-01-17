/*

Problem Statement

You work at Amazon’s Returns Department. A sequence of returned electronics arrives in the order they were processed by the customer service counter. Each item is marked either as “Reusable” (even product ID) or “Needs Repair” (odd product ID).

Goal
1. Group all Reusable items first so they can be quickly restocked.
2. Follow with all Repair items so they can be routed for inspection.
3. Maintain FIFO (First In, First Out) order within each category to preserve warranty claim tracking.

Example
    Returns Received: iPhone(1) → Laptop(4) → iPad(3) → Kindle(2) → Headphones(6) → Watch(5) → Speaker(7)
    Optimized Processing Order: Laptop(4) → Kindle(2) → Headphones(6) → iPhone(1) → iPad(3) → Watch(5) → Speaker(7)
Here, items with IDs 1, 3, 5, 7 are odd, so they come later; items 4, 2, 6 are even and go first.

Business Impact
1. Faster Restock: Reusable items are processed first, reducing time to return them to inventory.
2. Organized Repair Queue: Items needing attention are batched afterward, improving repair workflow.
3. Warranty Consistency: Preserving order within each category honors the FIFO principle, critical for warranty tracking.


Input/Output Format

Input

1. An integer n (number of returned items).
2. n integers representing product IDs:
    Even → "Reusable"
    Odd → "Needs Repair"


Output

A sequence of product IDs rearranged so that all even IDs appear first, followed by odd IDs, retaining the original order within each group.


Example

Input:
5
1 2 3 4 5

    
Output: 
2 4 1 3 5


Constraints

1. ( 1 <= n <= 10^5 )
2. ( 1 <= A[i] <= 10^9 )


*/


// SOURCE CODE



#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 
vector<int> sol(int n, vector<int>& A) {
    // you have to implement the sol function only
    vector<int> ans;
    queue<int> q;
    for(int i=0; i<A.size(); i++) {
        if(A[i]%2 == 0) {
            ans.push_back(A[i]);
        } else {
            q.push(A[i]);
        }
    }

    while(!q.empty()) {
        ans.push_back(q.front());
        q.pop();
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    // please don't modify the main function
    vector<int> result = sol(n, A);
    for (int i = 0; i < n; i++) {
        if (i == result.size() - 1) {
            cout << result[i];
        } else {
            cout << result[i] << " ";
        }
    }
    return 0;
}