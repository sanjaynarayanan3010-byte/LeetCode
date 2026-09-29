class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        long long cs = 0;
        int idx = 0;
        long long ans = 0;
        for(int i=0;i<N;i++){
            cs += nums[i];
            if(i - idx + 1 >= 3) {
                if(cs - nums[i] > nums[i]) ans = max(cs, ans);
            }
        }
        if(ans == 0) return -1;
        return ans;
    }
};