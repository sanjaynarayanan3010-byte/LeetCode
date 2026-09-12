class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        int N = nums.size();
        sort(nums.begin(), nums.end(),[](const vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        int size = 0;
        int le = INT_MIN;
        for(auto const& curr : nums){
            if(curr[0] >= le) {
                size++;
                le = curr[1];
            }
        }
        return N - size;
    }
};