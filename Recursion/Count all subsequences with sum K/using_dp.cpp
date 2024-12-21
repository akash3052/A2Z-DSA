class Solution {
  public:
    int solve(int index, int n, int target, vector<int> &input, vector<vector<int>> &dp){
        if(index == n){
            if(target == 0){
                return 1;
            }
            return 0;
        }
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        int res = solve(index+1, n, target, input, dp);
        if(input[index] <= target){
            res += solve(index+1, n, target - input[index], input, dp);
        }
        return dp[index][target] = res;
        
    }
    
    int perfectSum(vector<int>& arr, int target) {
        int index = 0, n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return solve(index, n, target, arr, dp);
        
    }
};


// The overall time complexity is O(n * (target + 1)), as there are n * (target + 1) states, each computed in O(1) time.
