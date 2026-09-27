class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int,int> mp;
        for(int i : nums) mp[i]++;
        int s = mp.size();
        vector<int> ans;
        while(s) {
            vector<int> temp;
            for(auto& it : mp){
                ans.push_back(it.first);
                it.second--;
                if(it.second == 0) temp.push_back(it.first);
            }
            for(int i : temp) mp.erase(i);
            s = mp.size();
        }
        return ans;
    }
};