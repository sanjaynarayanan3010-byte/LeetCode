class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int N = nums.size();
        int idx = 0;
        int ans = 0;
        unordered_map<int,int> mp;
        for(int i=0;i<N;i++){
            mp[nums[i]]++;
            while(mp[nums[i]] > k){
                mp[nums[idx]]--;
                idx++;
            }
            ans = max(ans, i - idx + 1);
        }
        return ans;
    }
};