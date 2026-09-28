class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        stack<int> st;
        for(char ch : s) {
            if(ch == ')') {
                st.pop();
            }
            else if(ch == '(') {
                st.push(ch);
                int size = st.size();
                ans = max(ans, size);
            }
        }
        return ans;
    }
};