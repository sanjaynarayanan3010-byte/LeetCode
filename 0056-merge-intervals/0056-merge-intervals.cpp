class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int N = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int currMin = intervals[0][0];
        int currMax = intervals[0][1];
        for(auto curr:intervals){
            if(curr[0] > currMax){
                ans.push_back({currMin, currMax});
                currMin = curr[0];
                currMax = curr[1];
            }
            else if(currMax < curr[1]){
                currMax = curr[1];
            }
        }
        ans.push_back({currMin, currMax});
        return ans;
    }
};