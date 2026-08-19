class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long N = nums.size();
        long t = 0;
        long tv = 0;
        for(int i=0;i<N;i++) {
            t += nums[i];
            tv += (nums[i] * i);
        }
        long cv = tv;
        long ans = cv;
        for(int i=1;i<N;i++){
            cv = cv - ((N-1) * nums[N-i]) + (t - nums[N-i]);
            ans = max(ans, cv);
        }
        return ans;
    }
};