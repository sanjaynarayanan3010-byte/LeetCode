class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int R=grid.size();
        int C=grid[0].size();
        vector<vector<int>> dp(R,vector<int>(C,0));
        dp[0][0]=grid[0][0];
        for(int i=1;i<C;i++) dp[0][i]=dp[0][i-1]+grid[0][i];
        for(int i=1;i<R;i++) dp[i][0]+=dp[i-1][0]+grid[i][0];
        for(int row=1;row<R;row++){
            for(int col=1;col<C;col++){
                dp[row][col]=min(dp[row][col-1],dp[row-1][col])+grid[row][col];
            }
        }
        // for(int row=0;row<R;row++){
        //     for(int col=0;col<C;col++){
        //         cout<<dp[row][col]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[R-1][C-1];
    }
};