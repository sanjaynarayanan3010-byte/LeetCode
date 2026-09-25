class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int N = nums.size();
        vector<int> ans(N);
        for(int i=0;i<N;i++){
            int c = 0;
            for(int idx=i+1;idx<N;idx++){
                if(nums[i] & 1 && nums[idx] % 2 == 0) c++;
                else if(nums[i] % 2 == 0 && nums[idx] & 1) c++; 
            }
            ans[i] = c;
        }
        return ans;
    }
};