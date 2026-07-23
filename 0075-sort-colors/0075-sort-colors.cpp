class Solution {
public:
    void sortColors(vector<int>& nums) {
        int N = nums.size();
        int p1 = 0, p2 = N-1;
        while(p2 > p1){
            while(p2 > p1 && nums[p1] == 0) p1++;
            if(nums[p2] == 0) swap(nums[p1], nums[p2]);
            p2--;
        }
        p2 = N-1;
        while(p2 > p1){
            while(p2 > p1 && nums[p2] == 2) p2--;
            if(nums[p1] == 2) swap(nums[p1], nums[p2]);
            p1++;
        }
    }
};