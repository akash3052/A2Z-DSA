class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i >= m || j >= n){
            return 0;
        }
        if(i == m-1 && j == n-1 && grid[i][j] != 1){
           return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int right = 0;
        int down = 0;
        if(i+1 < m && grid[i+1][j] != 1){
            down = solve(i+1, j, m, n, grid, dp);
        }
        if(j+1 < n && grid[i][j+1] != 1){
            right = solve(i, j+1, m, n, grid, dp);
        }
        return dp[i][j] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, obstacleGrid, dp);
    }
};


// Time and Space Complexity:
// Time Complexity: O(m * n), where m is the number of rows and n is the number of columns. 
//   Each cell is processed once due to memoization.
// Space Complexity: O(m * n) for the dp table and recursive call stack.



  
