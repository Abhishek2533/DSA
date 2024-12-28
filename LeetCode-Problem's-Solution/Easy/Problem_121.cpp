/*

121. Best Time to Buy and Sell Stock


You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.


Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.


Constraints:
1 <= prices.length <= 105
0 <= prices[i] <= 104

*/

// SOURCE CODE




// RECURSIVE

class Solution
{
public:
    int solve(vector<int> &prices, int i)
    {
        if (i == 2)
            return prices[i - 1] - prices[i - 2];
        int mini = *min_element(prices.begin(), prices.begin() + i - 1);
        int profit = prices[i - 1] - mini;
        return max(profit, solve(prices, i - 1));
    }
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 1)
            return 0;
        int ans = 0;
        return max(ans, solve(prices, prices.size()));
    }
};





// NON - RECURSIVE

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        int n = prices.size();
        for (int i = 0; i < n; i++)
        {
            if (prices[i] < minPrice)
            {
                minPrice = prices[i];
            }
            else if (prices[i] - minPrice > maxProfit)
            {
                maxProfit = prices[i] - minPrice;
            }
        }

        return maxProfit;
    }
};



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini=prices[0], profit=0;
        for(int i=1; i<n; i++) {
            int temp = prices[i] - mini;
            profit=max(profit, temp);
            mini = min(mini, prices[i]);
        }

        return profit;
    }
};