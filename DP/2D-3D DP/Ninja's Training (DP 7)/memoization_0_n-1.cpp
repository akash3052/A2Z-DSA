
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    int solve(int n, int day, int lastActivity, vector<vector<int>> &arr, vector<vector<int>> &dp){
        if(day >= n){
            return 0;
        }
        if(dp[day][lastActivity] != -1){
            return dp[day][lastActivity];
        }
        int res = INT_MIN;
        // Iterate over the 3 activities (0, 1, 2) and pick the best option that is not the same as the last day's activity
        for(int i = 0; i < 3; i++){
            if(i != lastActivity){
                res = max(res, arr[day][i] + solve(n, day+1, i, arr, dp));
            }
        }
        return dp[day][lastActivity] = res;
    }
    
    int maximumPoints(vector<vector<int>>& arr, int n) {
         // dp array to store the memoized results (n days, 4 possible values for lastActivity: 0, 1, 2, and 3 (no previous activity))
        vector<vector<int>> dp(n, vector<int>(4,-1));
        int day = 0;
        // Start from day 0 with no previous activity (represented by 3, which is out of bounds for [0, 1, 2])
        return solve(n, day, 3, arr, dp);
        
    }
};



