class Solution {
public:
    vector<int> countServers(int N, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](auto const& a, auto const& b){
            return a[1] < b[1];
        });
        vector<pair<int,int>> nums;
        for(int i=0;i<queries.size();i++) nums.push_back({queries[i], i});
        sort(nums.begin(), nums.end());
        unordered_map<int,int> mp;
        vector<int> ans(queries.size(), N);
        int l = 0, r = 0, i = 0;
        while(i < ans.size()){
            int top = nums[i].first, bot = top - x;
            if(r < logs.size() && logs[r][1] <= top) {
                mp[logs[r][0]]++;
                r++;
            }
            else {
                if(l < logs.size() && bot > logs[l][1]) {
                    mp[logs[l][0]]--;
                    if(!mp[logs[l][0]]) mp.erase(logs[l][0]);
                    l++;
                }
                else {
                    ans[nums[i].second] = N - mp.size();
                    i++;
                }
            }
        }
        return ans;
    }
};