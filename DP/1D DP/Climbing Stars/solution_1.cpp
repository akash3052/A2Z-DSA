class Solution {
public:
    int solve(int index, int n, vector<int> &dp){
        if(index == n){
            return 1;
        }
        if(index > n){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        return dp[index] = solve(index+1, n, dp) + solve(index+2, n, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(0, n, dp);
    }
};


TC = O(n)
SC = O(n)




  
