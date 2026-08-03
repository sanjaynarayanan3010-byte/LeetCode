class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int x) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        map<vector<long long>, long long> mp;
        vector<vector<int>> ans;
        long long target = x;
        for(int i=0;i<N-3;i++){
            for(int idx=i+1;idx<N-2;idx++){
                long long t = target - nums[i] - nums[idx];
                long long sti = idx+1;
                long long ei = N-1;
                while(sti < ei){
                    long long sum = nums[sti]+nums[ei];
                    if(t == sum) {
                        ans.push_back({nums[i], nums[idx],nums[sti],nums[ei]});
                        sti++;
                        ei--;
                        while(sti < ei && nums[sti] == nums[sti-1]) sti++;
                        while(sti < ei && nums[ei] == nums[ei+1]) ei--;
                    }
                    else if(t < sum){
                        ei--;
                    }
                    else {
                        sti++;
                    }
                }
                while(idx+1 < N && nums[idx] == nums[idx+1]) idx++;
            }
            while(i+1 < N && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};