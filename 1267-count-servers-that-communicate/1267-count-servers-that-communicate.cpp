class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int R, int C, int row, int col, int pr, int pc){
        if(row >= R || col >= C || row < 0 || col < 0 || vis[row][col]) return 0;
        if(grid[row][col] == 1) {
            vis[row][col] = 1;
            // cout << row << " " << col << endl;
            return 1 + dfs(grid, vis, R, C, row - 1, col, -1, 0) + dfs(grid, vis, R, C, row + 1, col, 1, 0) + dfs(grid, vis, R, C, row, col - 1, 0, -1) + dfs(grid, vis, R, C, row, col + 1, 0, 1);
        }
        else {
            return dfs(grid, vis, R, C, row + pr, col + pc, pr, pc);
        }
    }
    int countServers(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(R, vector<bool>(C, 0));
        for(int row=0;row<R;row++){
            for(int col=0;col<C;col++){
                if(grid[row][col] == 1 && !vis[row][col]) {
                    int add = dfs(grid, vis, R, C, row, col, -1, -1);
                    cout << add << endl;
                    if(add > 1) ans += add;
                }
            }
        }
        return ans;
    }
};