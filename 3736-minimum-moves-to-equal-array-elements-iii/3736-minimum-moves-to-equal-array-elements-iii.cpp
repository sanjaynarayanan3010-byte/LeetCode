class Solution {
public:
    int minMoves(vector<int>& nums) {
        int me = *max_element(nums.begin(), nums.end());
        int ans = 0;
        for(int i : nums) ans += (me - i);
        return ans;
    }
};