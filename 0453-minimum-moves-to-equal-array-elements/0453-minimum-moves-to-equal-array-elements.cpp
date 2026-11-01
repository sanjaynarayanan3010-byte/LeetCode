class Solution {
public:
    int minMoves(vector<int>& nums) {
        int N = nums.size();
        int me = *min_element(nums.begin(), nums.end());
        int ans = 0;
        for(int i : nums) ans += (i - me);
        return ans;
    }
};