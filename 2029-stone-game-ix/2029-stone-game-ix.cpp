class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> mp(3, 0);
        for(int i : stones) mp[i % 3]++;
        if(mp[0] % 2 == 0 && mp[1] > 0 && mp[2] > 0) return 1;
        else if(mp[0] % 2 != 0 && abs(mp[1] - mp[2]) > 2) return 1;
        return 0;
    }
};