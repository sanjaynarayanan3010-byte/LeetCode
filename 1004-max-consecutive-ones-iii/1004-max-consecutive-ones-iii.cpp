class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int N = nums.size();
        int idx = 0;
        int ans = 0;
        for(int i=0;i<N;i++){
            if(nums[i] == 0){
                while(k == 0){
                    if(nums[idx] == 0) k++;
                    idx++;
                }
                k--;
            }
            ans = max(ans, i - idx + 1);
        }
        return ans;
    }
};