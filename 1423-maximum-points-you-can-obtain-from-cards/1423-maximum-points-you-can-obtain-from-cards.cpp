class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int N = nums.size();
        int ls = 0;
        for(int i=0;i<k;i++) ls += nums[i];
        int ans = ls;
        int idx = k-1;
        int rs = 0;
        for(int i=N-1;i>=N - k;i--){
            rs += nums[i];
            ls -= nums[idx--];
            ans = max(ans, rs + ls);
        }
        return ans;
    }
};