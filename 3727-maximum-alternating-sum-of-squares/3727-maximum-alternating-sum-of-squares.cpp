class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int N = nums.size();
        for(int i=0;i<N;i++) nums[i] = abs(nums[i]);
        sort(nums.begin(), nums.end(), greater<>());
        long long ans = 0;
        int mid = N / 2;
        if(N % 2 == 0) mid--;
        for(int i=0;i<N;i++){
            if(i > mid) ans -= (nums[i] * nums[i]);
            else ans += (nums[i] * nums[i]);
        }
        return ans;
    }
};