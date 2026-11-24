class Solution {
public:
    int maxLength(vector<int>& nums) {
        int N = nums.size();
        int ans = 0;
        for (int i=0;i<N;i++) {
            long long pr = 1;
            int g = 0, l = 1;
            for (int idx=i;idx<N;idx++) {
                pr *= nums[idx];
                if(pr >= 25200) break;
                g = gcd(g, nums[idx]);
                l = l / gcd(l, nums[idx]) * nums[idx];
                if (pr == g * l) {
                    ans = max(ans, idx - i + 1);
                }
            }
        }
        return ans;
    }
};