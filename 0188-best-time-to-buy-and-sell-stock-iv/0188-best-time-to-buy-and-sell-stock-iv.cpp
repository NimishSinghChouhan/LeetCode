class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        
        if(k >= n/2){
            for(int i = 1; i < n; i++){
                ans += max(0, prices[i]-prices[i-1]);
            }
            return ans;
        }
        
        /**
         * dp[i, j] represents the max profit up until prices[j] using at most i transactions. 
         * dp[i, j] = max(dp[i, j-1], prices[j] - prices[jj] + dp[i-1, jj]) { jj in range of [0, j-1] }
         *          = max(dp[i, j-1], prices[j] + max(dp[i-1, jj] - prices[jj]))
         * dp[0, j] = 0; 0 transactions makes 0 profit
         * dp[i, 0] = 0; if there is only one price data point you can't make any transaction.
         */
        //only pad for k(transactions) dimension, not time dimension
        vector<vector<int>> dp(k+1, vector(n, 0));
        for(int i = 1; i <= k; i++){ //transactions
            // int hold = INT_MIN; //this gives WA!!
            int hold = dp[i-1][0] - prices[0];
            for(int j = 1; j < n; j++){ //days
                //hold: the max money we have if we hold a stock until j-1 day
                dp[i][j] = max(dp[i][j-1], prices[j] + hold);
                hold = max(hold, dp[i-1][j] - prices[j]);
            }
        }
        
        return dp[k][n-1];
    }
};