class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int N = nums.size();
        int c = 0, ans = 0;
        for(int i=0;i<N;i++){
            if(i > 0 && (nums[i-1] % k) == (nums[i] % k)) c++;
            else c = 1;
            if(((c-1) * (nums[i] % k)) % k == 0) ans = max(ans, c);
        }
        return ans;
    }
};