class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(nums[N-1] + 2, 0);
        for(int i : nums){
            dp[i+1] = max(dp[i+1], dp[i] + 1);
            dp[i] = max(dp[i], dp[i-1] + 1);
        }   
        return *max_element(dp.begin(), dp.end());
    }
};