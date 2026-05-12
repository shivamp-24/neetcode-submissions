class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2));
        // dp[i][j] -> max profit starting at i-th, j=0 no stock in hand, j=1 stock in hand
        for(int i=n-1; i>=0; i--) {
            // sell
            // sell allowed only when we have stock in hand
            // dp[i][1]
            int sell = prices[i] + dp[i+2][0];
            int skip = dp[i+1][1];
            dp[i][1] = max(sell, skip);

            // buy
            // buy allowed when no stock in hand
            // dp[i][0]
            int buy = -prices[i] + dp[i+1][1];
            skip = dp[i+1][0];
            dp[i][0] = max(buy, skip);
        }
        return dp[0][0];
    }
};
