class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        vector<vector<bool>> vis(R, vector<bool>(C, 0));
        int row = 0, col = 0;
        vis[row][col] = 1;
        while(true){
            int pr = row, pc = col;
            if(grid[row][col] == 'R') col++;
            else if(grid[row][col] == 'U') row--;
            else if(grid[row][col] == 'D') row++;
            else col--;
            if((row >= R || col >= C || row < 0 || col < 0) || vis[row][col]) return {pr, pc};
            vis[row][col] = 1;
        }
        return {};
    }
};