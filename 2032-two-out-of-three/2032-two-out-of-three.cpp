class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_set<int> st1;
        unordered_set<int> st2;
        unordered_set<int> st3;
        unordered_map<int,int> mp;
        for(int i : nums1) st1.insert(i);
        for(int i : nums2) st2.insert(i);
        for(int i : nums3) st3.insert(i); 
        for(int i : st1) mp[i]++;
        for(int i : st2) mp[i]++;
        for(int i : st3) mp[i]++;
        vector<int> ans;
        for(auto it : mp){
            if(it.second > 1) ans.push_back(it.first);
        }
        return ans;
    }
};