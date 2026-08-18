class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> f(51, 0);
        for (int i : nums)
            f[i]++;

        int res = -1;
        for (int i=0;i<N;i++){
            if (k == N || (f[nums[i]] == 1 && (k == 1|| !i || i == N-1))) res = max(res, nums[i]);
        }
        return res;
    }
};