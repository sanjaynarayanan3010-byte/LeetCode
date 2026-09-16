class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int, vector<int>> mp;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        for(auto it : mp) {
            if(it.second.size() == 3) {
                auto const& curr = it.second;
                if(curr[1] - curr[0] == curr[2] - curr[1]) ans++;
            }
        }
        return ans;
    }
};