class Solution {
public:
    vector<vector<int>> ans;
    void sum(int N, vector<int>& nums, int target, int s, vector<int>& temp, int index){
        if(s >= target){
            if(s == target) ans.push_back(temp);
            return;
        }
        for(int i=index;i<N;i++){
            temp.push_back(nums[i]);
            sum(N, nums, target, s+nums[i], temp, i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int N = nums.size();
        vector<int> temp;
        sum(N, nums, target, 0, temp, 0);
        return ans;
    }
};