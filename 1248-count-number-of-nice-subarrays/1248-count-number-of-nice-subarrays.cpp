class Solution {
public:
    int countOdd(vector<int>& nums, int k){
        int N = nums.size();
        int oc = 0;
        int sc = 0;
        int idx = 0;
        for(int i=0;i<N;i++){
            if(nums[i] & 1) oc++;
            while(oc > k){
                if(nums[idx] & 1) oc--;
                idx++;
            }
            sc += (i - idx + 1);
        }
        return sc;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countOdd(nums, k) - countOdd(nums, k-1);
    }
};