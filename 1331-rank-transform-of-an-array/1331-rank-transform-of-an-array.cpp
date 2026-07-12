class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_set<int> st;
        unordered_map<int,int> mp;
        vector<int> ans(arr);
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(st.find(arr[i]) == st.end()) {
                mp[arr[i]] = st.size()+1;
            }
            st.insert(arr[i]);
        }
        for(int i=0;i<arr.size();i++){
            ans[i] = mp[ans[i]];
        }
        return ans;
    }
};