class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int N = nums.size();
        int ans = INT_MAX;
        for(int i=0;i<N;i++){
            int cs = 0;
            for(int idx=i;idx<N;idx++){
                cs += nums[idx];
                if(idx - i + 1 >= l && idx - i + 1 <= r && cs > 0) ans = min(ans, cs);
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};