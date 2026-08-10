class Solution {
public:
    int calcSub(vector<int>& nums, int goal){
        if(goal == -1) return 0;
        int N = nums.size();
        int idx = 0;
        int s = 0;
        int c = 0;
        for(int i=0;i<N;i++){
            s += nums[i];
            while(s > goal) s -= nums[idx++];
            c += (i - idx + 1);
        }
        return c;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return calcSub(nums, goal) - calcSub(nums, goal-1);
    }
};