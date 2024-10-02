class Solution {
public:
    int solve(int start, int end, vector<int> &nums, vector<int> &dp){
        if(start > end){
            return 0;
        }
        if(dp[start] != -1){
            return dp[start];
        }
        int rob = nums[start] + solve(start+2, end, nums, dp);
        int notrob = solve(start+1, end, nums, dp);
        return dp[start] = max(rob, notrob);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        // Case 1: Rob houses from 0 to n-2 (excluding last house)
        int case1 = solve(0, n-2, nums, dp1);
        // Case 2: Rob houses from 1 to n-1 (excluding first house)
        int case2 = solve(1, n-1, nums, dp2);
        return max(case1, case2);
    }
};


// TC = O(n)
// SC = O(n)

