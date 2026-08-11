class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int N = nums.size();
        int sum = nums[0];
        int ans = nums[0];
        for(int i=1;i<N;i++){
            if(nums[i] != nums[i-1] + 1) break;
            else sum += nums[i];
            ans = max(sum, ans);
        }
        sort(nums.begin(), nums.end());
        for(int i:nums){
            if(i == ans){
                ans++;
            }
        }
        return ans;
    }
};