class Solution{
  public:
    int totalFruit(vector<int>& nums){
        int N = nums.size();
        unordered_set<int> st;
        int idx = 0;
        int ans = 0;
        for(int i=0;i<N;i++){
            st.insert(nums[i]);
            int size = st.size();
            if(size > 2){
                for(int d=i-2;d>=0;d--){
                    if(nums[d] != nums[d+1]){
                        st.erase(nums[d]);
                        idx = d+1;
                        break;
                    }
                }
            }
            ans = max(ans, i - idx + 1);
        }
        return ans;
    }
};