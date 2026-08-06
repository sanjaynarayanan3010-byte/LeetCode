class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();

        if(R == 1 && C == 1) return grid[0][0];

        int diff[5] = {0, 1, 0};

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> q;

        q.push(make_tuple(grid[0][0], 0, 0));
        vector<vector<int>> minDist(R, vector<int>(C, INT_MAX));

        while(!q.empty()){
            int d = get<0>(q.top());
            int row = get<1>(q.top());
            int col = get<2>(q.top());

            q.pop();

            if(minDist[row][col] < d) continue;
            for(int i=0;i<2;i++){
                int cr = row+diff[i];
                int cc = col+diff[i+1];

                if(cr >= 0 && cc >= 0 && cr < R && cc < C){
                    if(minDist[cr][cc] > d + grid[cr][cc]){
                        minDist[cr][cc] = d + grid[cr][cc];
                        q.push(make_tuple(d + grid[cr][cc], cr, cc));
                    }
                }
            }
        }
        return minDist[R-1][C-1];
    }
};