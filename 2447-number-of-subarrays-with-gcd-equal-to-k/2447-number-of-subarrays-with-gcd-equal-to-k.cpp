class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int N = nums.size();
        int c = 0;
        for(int i=0;i<N;i++){
            int gc = nums[i];
            for(int j=i;j<N;j++){
                gc = gcd(gc, nums[j]);
                if(gc == k) c++;
            }
        }
        return c;
    }
};