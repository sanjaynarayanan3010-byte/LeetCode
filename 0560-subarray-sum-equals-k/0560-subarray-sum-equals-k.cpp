class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int N = nums.size();
        unordered_map<int,int> mp;
        int currSum = 0;
        int totalCount = 0;

        mp[0] = 1;
        for(int i:nums){
            currSum += i;
            if(mp[currSum - k]){
                totalCount += mp[currSum - k];
            }
            mp[currSum]++; 
        }
        return totalCount;
    }
};