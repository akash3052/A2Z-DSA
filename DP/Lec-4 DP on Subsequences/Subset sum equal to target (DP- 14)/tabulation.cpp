class Solution {
  public:
    // bool solve(int index, int target, int n, vector<int> &input, vector<vector<int>> &dp){
    //     if(target == 0){
    //         return true;
    //     }
    //     if(index == n){
    //         return false;
    //     }
    //     if(dp[index][target] != -1){
    //         return dp[index][target];
    //     }
    //     bool exclude = solve(index+1, target, n, input, dp);
    //     bool include = false;
    //     if(input[index] <= target){
    //         include = solve(index+1, target - input[index], n, input, dp);
    //     }
    //     return dp[index][target] = exclude || include;
    // }
    
    bool isSubsetSum(vector<int>& arr, int target) {
       int index = 0, n = arr.size();
       vector<vector<bool>> dp(n+1, vector<bool>(target+1, 0));
       for(int i = 0; i <= n; i++){
           dp[i][0] = true;
       }
       for(int i = 1; i <= target; i++){
          dp[n][i] = false;
       }
       for(int index = n-1; index >= 0; index--){
           for(int target1 = 1; target1 <= target; target1++ ){
                bool exclude = dp[index+1][target1];
                bool include = false;
                if(arr[index] <= target1){
                    include = dp[index+1][target1 - arr[index]];
                }
                dp[index][target1] = exclude || include;
           }
       }
       return dp[0][target];
    }
};



