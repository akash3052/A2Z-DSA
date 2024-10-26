class Solution {
public:
    int solve(int index, int buy, int n, vector<int> &prices, vector<vector<int>> &dp){
        if(index == n){
            return 0;
        }
        if(dp[index][buy] != -1){
            return dp[index][buy];
        }
        int profit = 0;
        if(buy){
            profit = max(-prices[index] + solve(index+1, 0, n, prices, dp), solve(index+1, 1, n, prices, dp));
        }else{
            profit = max(prices[index] + solve(index+1, 1, n, prices, dp), solve(index+1, 0, n, prices, dp));
        }
        return dp[index][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solve(0, true, prices.size(), prices, dp);
    }
};


