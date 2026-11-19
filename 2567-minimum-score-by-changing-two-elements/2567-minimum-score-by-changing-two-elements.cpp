class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> rev(nums);
        vector<int> mid(nums);
        nums[0] = nums[N-1];
        nums[1] = nums[N-1];
        int ans = *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end());
        rev[N-1] = rev[0];
        rev[N-2] = rev[0];
        ans = min(ans, *max_element(rev.begin(), rev.end()) - *min_element(rev.begin(), rev.end()));
        mid[0] = mid[N/2];
        mid[N-1] = mid[N/2];
        return min(ans, *max_element(mid.begin(), mid.end()) - *min_element(mid.begin(), mid.end()));
    }
};