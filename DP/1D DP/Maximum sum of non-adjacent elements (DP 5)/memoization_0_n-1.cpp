class Solution {
public:
    int solve(int index, int n, vector<int> &nums, vector<int> &dp){
        if(index >= n){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int rob = nums[index] + solve(index + 2, n, nums, dp);
        int notrob = solve(index+1, n, nums, dp);
        return dp[index] = max(rob, notrob);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return solve(0, n, nums, dp);
    }
};


