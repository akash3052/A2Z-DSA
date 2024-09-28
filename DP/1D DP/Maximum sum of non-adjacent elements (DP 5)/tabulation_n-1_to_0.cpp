class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[n-1] = nums[n-1];
        for(int index = n-2; index >= 0; index--){
            int rob = nums[index];
            if(index+2 < n){
                rob += dp[index+2];
            }
            int notrob = dp[index+1];
            dp[index] = max(rob, notrob);
        }
        return dp[0];
    }
};


// TC = O(n)
// SC = O(n)
