class Solution {
public:
    int diff[5] = {0, -1, 0, 1, 0};
    int bfs(int R, int C, vector<vector<bool>>& vis, vector<vector<int>>& grid, int r, int c, queue<pair<int,int>>& q, int k){
        vis[r][c] = 1;
        long long sum = 0;
        q.push({r, c});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();
            sum += grid[row][col];
            for(int i=0;i<4;i++){
                int cr = row + diff[i];
                int cc = col + diff[i+1];
                if(cr >= 0 && cc >= 0 && cr < R && cc < C && !vis[cr][cc] && grid[cr][cc] > 0){
                    q.push({cr, cc});
                    vis[cr][cc] = 1;
                }
            }
        }
        return sum % k == 0;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int R = grid.size(), C = grid[0].size();
        vector<vector<bool>> vis(R, vector<bool>(C, 0));
        long long ans = 0;
        queue<pair<int,int>> q;
        for(int row=0;row<R;row++){
            for(int col=0;col<C;col++){
                if(!vis[row][col] && grid[row][col] > 0) ans += bfs(R, C, vis, grid, row, col, q, k);
            }
        }
        return ans;
    }
};