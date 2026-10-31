class Solution {
public:
    int mod = 1e9 + 7;
    int dfs(int R, int C, int row, int col, int prev, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        if(row == R-1 && col == C-1) return 1;
        if(row >= R || col >= C || col < 0 || row < 0) return 0;
        if(prev != 2 && dp[row][col][prev] != -1) return dp[row][col][prev];
        if(grid[row][col] == 1) {
            if(prev == 0) return dp[row][col][prev] = dfs(R, C, row+1, col, 1, grid, dp);
            else return dp[row][col][prev] = dfs(R, C, row, col + 1, 0, grid, dp);
        }
        return dp[row][col][prev] = (dfs(R, C, row+1, col, 1, grid, dp) + dfs(R, C, row, col+1, 0, grid, dp)) % mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        vector<vector<vector<int>>> dp(R+1, vector<vector<int>> (C+1, vector<int> (3, -1)));
        return dfs(R, C, 0, 0, 2, grid, dp) % mod;
    }
};