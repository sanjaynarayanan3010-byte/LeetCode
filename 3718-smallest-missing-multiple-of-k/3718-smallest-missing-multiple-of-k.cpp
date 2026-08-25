class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        int temp = k;
        for(int i : nums) st.insert(i);
        while(1){
            if(st.find(k) == st.end()) return k;
            k += temp;
        }
        return k;
    }
};