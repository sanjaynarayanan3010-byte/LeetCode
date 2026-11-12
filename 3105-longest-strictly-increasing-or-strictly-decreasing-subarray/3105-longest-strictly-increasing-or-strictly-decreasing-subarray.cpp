class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int N = nums.size();
        int ans = 1, ctr = 1;
        for(int i=0;i<N-1;i++){
            if(nums[i] < nums[i+1]) ctr++;
            else {
                ans = max(ans, ctr);
                ctr = 1;
            }
        }
        ans = max(ans, ctr);
        ctr = 1;
        for(int i=N-1;i>0;i--){
            if(nums[i-1] > nums[i]) ctr++;
            else {
                ans = max(ans, ctr);
                ctr = 1;
            }
        }
        ans = max(ans, ctr);
        return ans;
    }
};