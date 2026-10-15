class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        int N = nums.size();
        for(int i=0;i<N;i++){
            unordered_set<int> st;
            for(int idx=i;idx<N;idx++){
                st.insert(nums[idx]);
                if(i != idx) ans += (st.size() * st.size());
            }
            ans++;
        }
        return ans;
    }
};