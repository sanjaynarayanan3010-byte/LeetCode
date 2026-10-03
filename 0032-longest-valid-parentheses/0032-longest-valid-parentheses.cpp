class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int ans = 0, N = s.size();
        st.push(-1);
        for(int i=0;i<N;i++){
            if(s[i] == '(' || st.empty()) st.push(i);
            if(s[i] == ')'){
                st.pop();
                if(st.empty()) {
                    st.push(i);
                }
                else {
                    ans = max(ans, i - st.top());
                }
            }
        }
        return ans;
    }
};