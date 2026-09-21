class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& nums) {
        int N = nums.size();
        int c = 0;
        sort(nums.begin(), nums.end());

        for(int i=0;i<N;i++){
            int stf = nums[i][0];
            int enf = nums[i][1];
            for(int idx=i+1;idx<N;idx++){
                int sts = nums[idx][0];
                int ens = nums[idx][1];
                if(sts <= enf) c++;
            }
        }
        return c;
    }
};