bool solve(int index, int n, int target, vector<int> &input, vector<vector<int>> &dp){
    if(target == 0){
        return true;
    }
    if(index == n){
        return false;
    }
    if(dp[index][target] != -1){
        return dp[index][target];
    }
    bool exclude = solve(index+1, n, target, input, dp);
    bool include = false;
    if(input[index] <= target){
        include = solve(index+1, n, target-input[index], input, dp);
    }
    return dp[index][target] = exclude || include;
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Write your code here
    int index = 0;
    vector<vector<int>> dp(n+1, vector<int>(k+1,-1));
    return solve(index, n, k, a, dp);
}

// **Time Complexity:** O(n * k), **Space Complexity:** O(n * k).
