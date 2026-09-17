class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int, vector<int>> mp;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        for(auto it : mp) {
            if(it.second.size() >= 3) {
                auto const& curr = it.second;
                int diff = curr[1] - curr[0];
                bool f = 0;
                for(int i=1;i<it.second.size();i++){
                    if(diff != (curr[i] - curr[i-1])) f = 1;
                }
                if(!f) ans++;
            }
        }
        return ans;
    }
};