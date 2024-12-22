// User function template for C++

class Solution {
  public:
    bool solve(int index, int target, int n, vector<int> &input, vector<vector<int>> &dp){
        if(target == 0){
            return true;
        }
        if(index == n){
            return false;
        }
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        bool exclude = solve(index+1, target, n, input, dp);
        bool include = false;
        if(input[index] <= target){
            include = solve(index+1, target - input[index], n, input, dp);
        }
        return dp[index][target] = exclude || include;
    }
    
    bool isSubsetSum(vector<int>& arr, int target) {
       int index = 0, n = arr.size();
       vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
       return solve(index, target, n, arr, dp);
    }
};

// TC = O(n*target)
// SC = O(n*target)
  
