class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> bestBuy(n);

        bestBuy[0] = prices[0];

        // Find minimum buying price up to each day
        for (int i = 1; i < n; i++) {
            bestBuy[i] = min(bestBuy[i - 1], prices[i]);
        }

        int maxProfit = 0;

        // Calculate maximum profit
        for (int i = 0; i < n; i ++) { 
            int currProfit = prices[i] - bestBuy[i];
            maxProfit = max(maxProfit, currProfit);
        }

        return maxProfit;
    }
};