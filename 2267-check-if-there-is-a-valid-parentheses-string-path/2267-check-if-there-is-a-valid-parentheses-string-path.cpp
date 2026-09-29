class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int R = grid.size(), C = grid[0].size();
        if(grid[0][0] == ')') return 0;
        vector<vector<unordered_set<int>>> dp(R, vector<unordered_set<int>> (C));
        dp[0][0].insert(1);
        for(int col=1;col<C;col++) {
            for(int i : dp[0][col-1]) {
                if(grid[0][col] == ')') {
                    if(i == 0) continue;
                    else dp[0][col].insert(i - 1);
                }
                else dp[0][col].insert(i + 1);
            }
        }
        for(int row=1;row<R;row++) {
            for(int i : dp[row-1][0]) {
                if(grid[row][0] == ')') {
                    if(i == 0) continue;
                    else dp[row][0].insert(i - 1);
                } 
                else dp[row][0].insert(i+1);
            }
        }
        for(int row=1;row<R;row++){
            for(int col=1;col<C;col++){
                if(grid[row][col] == '('){
                    for(int i : dp[row][col-1]){
                        dp[row][col].insert(i + 1);
                    }
                    for(int i : dp[row-1][col]) dp[row][col].insert(i + 1);
                }
                else {
                    for(int i : dp[row][col-1]){
                        if(i == 0) continue;
                        dp[row][col].insert(i - 1);
                    }
                    for(int i : dp[row-1][col]) {
                        if(i == 0) continue;
                        dp[row][col].insert(i - 1);
                    }
                }
            }
        }
        for(int i : dp[R-1][C-1]) {
            if(i == 0) return 1;
        }
        return 0;
    }
};