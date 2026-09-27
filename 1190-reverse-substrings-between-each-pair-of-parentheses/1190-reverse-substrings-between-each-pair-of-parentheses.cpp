class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        string ans;
        for(char ch : s) {
            if(ch == ')'){
                string temp = "";
                while(st.top() != '(') {
                    char c = st.top();
                    temp += c;
                    st.pop();
                }
                st.pop();
                for(char c : temp) st.push(c);
            }
            else st.push(ch);
        }
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};