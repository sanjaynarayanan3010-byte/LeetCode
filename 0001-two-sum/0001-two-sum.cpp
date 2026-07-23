class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int N = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<N;i++){
            if(mp[target - nums[i]]){
                return {mp[target - nums[i]] - 1, i};
            }
            mp[nums[i]] = i+1;
        }
        return {-1, -1};
    }
};