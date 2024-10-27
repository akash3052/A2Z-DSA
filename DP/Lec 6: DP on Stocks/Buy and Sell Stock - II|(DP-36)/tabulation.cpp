class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        // write the base condition from recursion
        dp[n][0] = 0;
        dp[n][1] = 0;
        // run for loop for all the variables which are changing in the recursive call
        // If recursion is running from 0 to n-1, do opposite in tabulation (n-1 to 0)
        for(int index = n-1; index >= 0; index--){
            for(int buy = 0; buy <= 1 ; buy++){
                // copy the entire code from recursion and replace solve() with dp
                long profit = 0;
                if(buy){
                    profit = max(-prices[index] + dp[index+1][0], dp[index+1][1]);
                }else{
                    profit = max(prices[index] + dp[index+1][1], dp[index+1][0]);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }
};


