class Solution {
public:
    int maxRob(vector<int>& nums,int N, int currSum, int index, int ans, vector<vector<int>>& dp){
        if(index+2 >= N) return currSum;
        if(dp[index][currSum] != -1) return dp[index][currSum];
        for(int i=index+2; i<N;i++){
            ans = max(ans, maxRob(nums, N, currSum + nums[i], i, ans, dp));
        }
        return dp[index][currSum] = ans;
    }
    int rob(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> dp(N, vector<int>(10000,-1));
        return max(maxRob(nums, N, nums[0], 0, 0, dp), (N > 1 ? maxRob(nums, N, nums[1], 1, 0, dp) : 0));
    }
};