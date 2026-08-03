class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int R = nums1.size();
        int C = nums2.size();
        int ans = 0;
        vector<vector<int>> dp(R+1, vector<int> (C+1,0));
        for(int row=1;row<=R;row++){
            for(int col=1;col<=C;col++){
                if(nums1[row-1] == nums2[col-1]) dp[row][col] = dp[row-1][col-1] + 1;
                ans = max(ans, dp[row][col]);
            }
        }
        return ans;
    }
};