class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int N = intervals.size();
        sort(intervals.begin(), intervals.end());
        int newMin = newInterval[0];
        int newMax = newInterval[1];
        bool added = 0;
        bool setMin = 0;
        vector<vector<int>> ans;

        for(auto curr:intervals){
            if(!added && !setMin && curr[0] > newMin){
                setMin = 1;
            }
            if(!added && !setMin && curr[0] <= newMin && newMin <= curr[1]){
                newMin = curr[0];
                setMin = 1;
            }
            if(!added && setMin && newMax < curr[0]){
                ans.push_back({newMin, newMax});
                added = 1;
                newMin = -1;
                newMax = -1;
                setMin = 0;
            }
            else if(!added && setMin && newMax <= curr[1] && newMax >= curr[0]){
                ans.push_back({newMin, curr[1]});
                added = 1;
                newMin = -1;
                newMax = -1;
                setMin = 0;
            }
            if(!setMin){
                int size = ans.size();
                int prev = (size >= 1 ? ans[size-1][1] : -1);
                if(prev != curr[1]){
                    ans.push_back({curr[0], curr[1]});
                }
            }
            
        }
        if(newMax != -1 && newMin != -1){
            ans.push_back({newMin, newMax});
        }
        return ans;
    }
};