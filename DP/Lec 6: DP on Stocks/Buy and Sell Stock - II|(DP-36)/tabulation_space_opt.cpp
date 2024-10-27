class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2, 0), curr(2,0);
        // write the base condition from recursion
        ahead[0] = 0;
        ahead[1] = 0;
        // run for loop for all the variables which are changing in the recursive call
        // If recursion is running from 0 to n-1, do opposite in tabulation (n-1 to 0)
        for(int index = n-1; index >= 0; index--){
            for(int buy = 0; buy <= 1 ; buy++){
                // copy the entire code from recursion and replace solve() with dp
                long profit = 0;
                if(buy){
                    profit = max(-prices[index] + ahead[0], ahead[1]);
                }else{
                    profit = max(prices[index] + ahead[1], ahead[0]);
                }
                curr[buy] = profit;
            }
            ahead = curr;
        }
        return ahead[1];
    }
};


// TC = O(n*2)
// SC = O(4) [2 vectors of size 2, we can also take 4 variables instead of 2 vectors]

