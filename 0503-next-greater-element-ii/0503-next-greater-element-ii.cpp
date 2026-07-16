class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int N = nums.size();
        vector<int> newNums(N*2);
        for(int i=0;i<N;i++){
            newNums[i] = nums[i];
            newNums[i+N] = nums[i];
        }
        vector<int> ans(N,-1);
        stack<int> st;
        for(int i=0;i<N*2;i++){
            while(!st.empty() && newNums[st.top()] < newNums[i]){
                ans[st.top() % N] = newNums[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};