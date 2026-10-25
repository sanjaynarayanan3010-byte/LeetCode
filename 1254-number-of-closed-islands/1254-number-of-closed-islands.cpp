class Solution {
public:
    int diff[5] = {0, -1, 0, 1, 0};
    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int R, int C, int row, int col, int no){
        queue<pair<int,int>> q;
        q.push({row, col});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            grid[r][c] = no;
            for(int i=0;i<4;i++){
                int cr = r + diff[i];
                int cc = c + diff[i+1];
                if(cr >= 0 && cc >= 0 && cr < R && cc < C && !grid[cr][cc] && !vis[cr][cc]) q.push({cr, cc});
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        vector<vector<bool>> vis(R, vector<bool>(C, 0));
        queue<pair<int,int>> q;
        int ans = 0;
        for(int row=0;row<R;row++){
            if(grid[row][0] == 0) q.push({row, 0});
            if(grid[row][C-1] == 0) q.push({row, C-1});
        }
        for(int col=0;col<C;col++){
            if(grid[0][col] == 0) q.push({0, col});
            if(grid[R-1][col] == 0) q.push({R-1, col});
        }
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            grid[row][col] = -1;
            for(int i=0;i<4;i++){
                int cr = row + diff[i];
                int cc = col + diff[i+1];

                if(cr >= 0 && cc >= 0 && cc < C && cr < R && grid[cr][cc] == 0) q.push({cr, cc});
            }
        }
        int no = 2;
        for(int row=0;row<R;row++){
            for(int col=0;col<C;col++){
                // cout << grid[row][col] << " ";
                if(!vis[row][col] && grid[row][col] == 0) {
                    bfs(grid, vis, R, C, row, col, no);
                    no++;
                }
            }
            // cout << endl;
        }
        unordered_set<int> st;
        for(int row=0;row<R;row++){
            for(int col=0;col<C;col++){
                if(grid[row][col] != 1 && grid[row][col] != -1) st.insert(grid[row][col]);
            }
        }
        return st.size();
    }
};