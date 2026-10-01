class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        stack<char> st;
        unordered_map<string, int> q;
        for(string s : chunks) {
            for(char ch : s){
                if(isalpha(ch) || (ch == ' ' && !st.empty() && isalpha(st.top()))) st.push(ch);
                else if(ch == '-' && !st.empty()) {
                    if(isalpha(st.top())) st.push(ch);
                    else {
                        st.pop();
                        st.push(' ');
                    }
                }
                else if(!st.empty()) {
                    st.pop();
                    st.push(' ');
                }
            }
        }
        // while(!st.empty()) {
        //     cout << st.top();
        //     st.pop();
        // }
        vector<int> ans;
        while(!st.empty() && !isalpha(st.top())) st.pop();
        string s = "";
        while(!st.empty()){
            if(st.top() == ' '){
                reverse(s.begin(), s.end());
                // while(!isalpha(s.back())) s.pop_back();
                // cout << s << endl;
                q[s]++;
                s = "";
            }
            else s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        // while(!isalpha(s.back())) s.pop_back();
        // cout << s;
        q[s]++;
        // for(auto it : q) cout << it.first << " " << it.second << endl;
        for(string i : queries) {
            ans.push_back(q[i]);
        }
        return ans;
    }
};