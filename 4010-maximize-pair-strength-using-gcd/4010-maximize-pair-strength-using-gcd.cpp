class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                ans = max(ans, ((long long)nums[i] * (long long)nums[j]) /((long long)gcd((long long)nums[i], (long long)nums[j]) * (long long)gcd((long long)nums[i], (long long)nums[j])));
            }
        }
        return (long long)ans;
    }
};