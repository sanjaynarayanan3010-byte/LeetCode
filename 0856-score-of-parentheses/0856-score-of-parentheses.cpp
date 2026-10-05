class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<string> st;
        for(char ch : s){
            if(ch == '(') st.push("(");
            else {
                if(st.top() == "(") {
                    st.pop();
                    st.push("1");
                }
                else{
                    int e = stoi(st.top());
                    e *= 2;
                    st.pop();
                    st.pop();
                    st.push(to_string(e));
                }
            }
            int sum = 0;
            while(!st.empty() && st.top() != "(" && st.top() != ")"){
                sum += stoi(st.top());
                st.pop();
            }
            if(sum > 0) {
                st.push(to_string(sum));
            }
        }
        return stoi(st.top());
    }
};