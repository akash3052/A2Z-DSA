class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp){
        // If the current position is out of bounds or it's an obstacle
        if(i >= m || j >= n || grid[i][j] == 1) {
            return 0;
        }

        // If we reached the bottom-right corner, return 1 (valid path)
        if(i == m-1 && j == n-1) {
            return 1;
        }

        // If the current cell has already been computed, return its value
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // Calculate paths moving right and down
        int right = solve(i, j+1, m, n, grid, dp);
        int down = solve(i+1, j, m, n, grid, dp);

        // Store the result in dp array and return it
        return dp[i][j] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        // If the starting point itself is blocked, return 0
        if(obstacleGrid[0][0] == 1) {
            return 0;
        }

        // Create a dp array initialized to -1
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // Start from the top-left corner
        return solve(0, 0, m, n, obstacleGrid, dp);
    }
};
