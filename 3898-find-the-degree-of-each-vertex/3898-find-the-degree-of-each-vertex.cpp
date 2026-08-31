class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<vector<int>> mp(matrix.size());
        vector<int> ans;
        int ci = 0;
        for(auto const& curr : matrix){
            for(int i=0;i<curr.size();i++){
                if(curr[i] == 1){
                    mp[ci].push_back(i);
                }
            }
            ans.push_back(mp[ci].size());
            ci++;
        }
        return ans;
    }
};