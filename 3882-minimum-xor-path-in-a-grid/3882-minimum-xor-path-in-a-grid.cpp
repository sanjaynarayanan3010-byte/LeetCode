class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int R=grid.size(),C=grid[0].size();
        vector<vector<unordered_set<int>>> dp(R+1, vector<unordered_set<int>>(C+1));
        for(int row=1;row<=R;row++){
            for(int col=1;col<=C;col++){
                if(row == 1 && col == 1) {
                    dp[row][col].insert(grid[row-1][col-1]);
                    continue;
                }
                int curr = grid[row-1][col-1];
                for(int i : dp[row-1][col]) dp[row][col].insert(curr ^ i);
                for(int i : dp[row][col-1]) dp[row][col].insert(curr ^ i);
            }
        }
        int mv = INT_MAX;
        for(int i : dp[R][C]) mv = min(mv, i);
        return mv; 
    }
};