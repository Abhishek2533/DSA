/*

Problem Statement

You're on YouTube's monetization team. Given data about viewer engagement during different times of a video, find the best times to place ads to maximize both revenue and user experience. You can place up to k ads in a video of length n seconds. This directly affects millions of creators' earnings and billions of viewers' experience. Finding the right balance is crucial!


Input Format

n: An integer (1 ≤ n ≤ 10^5) representing the length of the video in seconds.
k: An integer (1 ≤ k ≤ n) representing the maximum number of ads allowed.
viewer_retention: A list of integers (1 ≤ viewer_retention[i] ≤ 1000) representing the percentage of viewers at each second.
ad_value: A list of integers (1 ≤ ad_value[i] ≤ 1000) representing the potential revenue at each second.


Output Format

Return a list of integers representing the indices where ads should be placed to maximize the total score. (0-based)


Constraints

1. 1 ≤ n*k ≤ 10^6
2. 1 ≤ k ≤ n
3. 1 ≤ viewer_retention[i] ≤ 100
4. 1 ≤ ad_value[i] ≤ 1000
5. Ads cannot be placed consecutively that is if you place an ad at i-th second, you cannot place an ad at i+1-th second.


*/


// SOURCE CODE



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// you just need to implement the function
vector<int> maximizeAdRevenue(const vector<int> &viewer_retention, const vector<int> &ad_value, int k)
{   // write the code here
    int n=(int)viewer_retention.size();
    if(n==0 || k==0) return {};

    //precompute score for each second
    vector<long long> score(n);
    for(int i=0; i<n; i++) {
        score[i] = 1LL*viewer_retention[i]*ad_value[i];
    }

    vector<vector<long long>> dp(n+1, vector<long long>(k+1, 0LL));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            // do not place an ad at second i
            long long best = dp[i-1][j];

            // place an ad at second i
            if(i>=2) {
                best = max(best, dp[i-2][j-1] + score[i-1]);
            } else {
                best = max(best, score[i-1]);
            }

            dp[i][j]=best;
        }
    }


    // backtrack to find which indices were chosen
    vector<int> choosen;
    int i=n, j=k;
    while(i>0 && j>0) {
        // if dp[i][j] came from dp[i-1][j], then we did not place ad at i
        if(dp[i][j] == dp[i-1][j]) i-=1;
        else {
            // otherwise we place ad at second i
            choosen.push_back(i-1);
            i-=2;
            j-=1;
        }
    }

    reverse(choosen.begin(), choosen.end());
    return choosen;
}

int main() {
    vector<int> viewer_retention;
    vector<int> ad_value;
    int k;
    int n;

    cin >> n; 
    cin >> k;
    // please don't change the main function
    for (int i = 0; i < n; ++i) {
        int retention;
        cin >> retention;
        viewer_retention.push_back(retention);
    }
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        ad_value.push_back(value);
    }

    vector<int> result = maximizeAdRevenue(viewer_retention, ad_value, k);
    for (int i = 0; i < result.size(); ++i) {
        if (i == result.size() - 1) {
            cout << result[i];
        } else {
            cout << result[i] << " ";
        }
    }
    return 0;
}


/*

input:
 6 2 
 80 60 70 50 90 40
 100 80 90 70 120 50

expected output:
 0 4

*/