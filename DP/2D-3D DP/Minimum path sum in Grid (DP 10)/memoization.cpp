class Solution {
public:
    // note akash : intially I was returning int, it was throwing error because of overflow(since we are adding something in INT_MAX)
    long long solve(int i, int j, int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i == row-1 && j == col-1){
            return grid[i][j];
        }
        if(i >= row || j >= col){
            return INT_MAX;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        long long right = grid[i][j] + solve(i, j+1, row, col, grid, dp);
        long long down = grid[i][j] + solve(i+1, j, row, col, grid, dp);
        return dp[i][j] = min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, -1));
        return solve(0, 0, row, col, grid, dp);
    }
};


TC = O(row * col)
SC = O(row * col)
