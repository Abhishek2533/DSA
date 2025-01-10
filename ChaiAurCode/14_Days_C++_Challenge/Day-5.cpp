/*

Problem Statement

You are developing a stock market analysis tool for a financial application. Traders and investors often need to monitor peak stock prices over specific time windows to make better trading decisions. Your task is to implement a feature that analyzes historical stock prices and identifies the maximum price within a moving window.

For instance, in a trading day, the application will take the last k minutes' stock prices as a sliding window and display the highest price during that period. This helps traders quickly spot trends and evaluate opportunities in real time.


Input Format

prices: A list of integers representing stock prices at regular intervals.
k: An integer representing the size of the sliding window (number of consecutive intervals).


Output Format

Return a list of integers where each element represents the maximum price in the respective sliding window.


Example

Input:

prices = [10, 7, 12, 9, 8, 15],
k = 3

    
Output: 

[12, 12, 12, 15]

Explanation: Window [10,7,12] -> max = 12 Window [7,12,9] -> max = 12 Window [12,9,8] -> max = 12 Window [9,8,15] -> max = 15



Constraints:
1. 1 ≤ prices.length ≤ 10^5
2. 1 ≤ k ≤ prices.length
3. 0 ≤ prices[i] ≤ 10^4


*/


// SOURCE CODE




// METHOD - 1:

#include <vector>
#include<bits/stdc++.h>


using namespace std;

// you just need to implement the function
vector<int> maxInRollingWindow(vector<int>& prices, int k) {
    // you need to write the code here
    vector<int> ans;
    for(int i=0; i<prices.size(); i++) {
        if(i+k <= prices.size()) {
            int val = *max_element(prices.begin()+i,prices.begin()+i+k);
            ans.push_back(val);
        }
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

   // please do not remove the following code
    vector<int> result = maxInRollingWindow(prices, k);
    for(int i = 0; i < result.size(); i++) {
        if(i == result.size() - 1) {
            cout << result[i];
        } else {
            cout << result[i] << " ";
        }
    }

    return 0;
}






// METHOD - 2:

#include <vector>
#include<bits/stdc++.h>


using namespace std;

// you just need to implement the function
vector<int> maxInRollingWindow(vector<int>& prices, int k) {
    // you need to write the code here
    vector<int> ans;
    deque<int> dq;
    for(int i=0; i<prices.size(); i++) {
        if(!dq.empty() && dq.front()==i-k) dq.pop_front();

        while (!dq.empty() && prices[dq.back()] < prices[i]) {
        {
            dq.pop_back();
        }

        dq.push_back(i);
        
        if(i >= k-1) ans.push_back(prices[dq.front()]);
    }
    return ans;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

   // please do not remove the following code
    vector<int> result = maxInRollingWindow(prices, k);
    for(int i = 0; i < result.size(); i++) {
        if(i == result.size() - 1) {
            cout << result[i];
        } else {
            cout << result[i] << " ";
        }
    }

    return 0;
}