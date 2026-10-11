class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans = 0;
        int N = nums.size();
        for(int i=1;i<=N;i++){
            if(N % i == 0) ans += (nums[i-1] * nums[i-1]);
        }
        return ans;
    }
};