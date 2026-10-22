class Solution {
public:
    int minOperations(vector<int>& nums) {
        int N = nums.size();
        if(N == 1) return 0;
        int inc = 0, dec = 0;
        for(int i=1;i<N;i++){
            if(nums[i-1] > nums[i]) inc++;
            else dec++;
        }
        if(nums[N-1] > nums[0]) {
            if(dec == N-1) return 0;
            if(dec == 1){
                for(int i=1;i<N;i++) {
                    if(nums[i-1] < nums[i]) return min(i, N - i) + 1;
                }
            }
        }
        if(nums[0] > nums[N-1]) {
            if(inc == N-1) return 1;
            if(inc == 1){
                for(int i=1;i<N;i++){
                    if(nums[i] < nums[i-1]) return min(i, N - i + 2);
                }
            }
        }
        return -1;
    }
};