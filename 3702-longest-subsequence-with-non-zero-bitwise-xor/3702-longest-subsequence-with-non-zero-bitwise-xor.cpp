class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        long long s = 0;
        for(int i:nums) s += i;
        if(s == 0) return 0;
        int t = 0;
        for(int i:nums) t ^= i;
        if(t == 0) return nums.size() - 1;
        else return nums.size();
    }
};