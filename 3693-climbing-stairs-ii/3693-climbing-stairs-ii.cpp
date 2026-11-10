class Solution {
public:
    int climbStairs(int N, vector<int>& costs) {
        vector<int> dp(N+1, 0);
        for(int i=1;i<=N;i++){
            if(i == 1) dp[i] = costs[0] + 1 + dp[0];
            else if(i == 2) dp[i] = min(costs[i-1] + 4 + dp[0], costs[i-1] + 1 + dp[1]);
            else {
                dp[i] = min({costs[i-1] + 1 + dp[i-1], costs[i-1] + 4 + dp[i-2], costs[i-1] + 9 + dp[i-3]});
            }
            // cout << dp[i] << ' ';
        }
        return dp[N];
    }
};