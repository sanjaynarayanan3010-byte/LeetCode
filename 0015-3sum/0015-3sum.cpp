class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int prev = 1e9+7;
        for(int i=0;i<N-2;i++){
            if(prev == nums[i]) continue;
            int startIndex = i+1;
            int endIndex = N-1;
            while(endIndex > startIndex){
                if(startIndex < endIndex && nums[startIndex] + nums[endIndex] == (-1 * nums[i])){
                    ans.push_back({nums[i], nums[startIndex], nums[endIndex]});
                    while(startIndex < endIndex && nums[endIndex] == nums[endIndex - 1]) endIndex--;
                    while(startIndex < endIndex && nums[startIndex] == nums[startIndex + 1]) startIndex++;
                    startIndex++;
                    endIndex--;
                }
                else if(nums[startIndex] + nums[endIndex] > (-1 * nums[i])) endIndex--;
                else if(nums[startIndex] + nums[endIndex] < (-1 * nums[i])) startIndex++;
            }
            prev = nums[i];
        }
        return ans;
    }
};