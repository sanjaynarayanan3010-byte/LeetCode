class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> st;
        unordered_set<int> sl;
        for(int i:nums1) st.insert(i);
        for(int i:nums2) sl.insert(i);
        for(int i:sl){
            if(st.count(i)) ans.push_back(i);
        }
        return ans;
    }
};