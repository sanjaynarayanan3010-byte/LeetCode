class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int minElement = INT_MAX;
        for(int i:nums) minElement = min(minElement, i);
        map<int,int> mp;
        for(int i:nums) mp[i]++;
        int seq = 1;
        int total = 0;
        int prev = minElement;
        for(auto it:mp){
            if(it.first == prev){
                continue;
            }
            if(it.first == (prev + 1)){
                seq++;
            }
            else {
                total = max(total, seq);
                seq = 1;
            }
            prev = it.first;
        }
        return max(total, seq);
    }
};