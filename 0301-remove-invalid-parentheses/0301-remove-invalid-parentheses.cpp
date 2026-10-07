class Solution {
public:
    vector<pair<string,int>> strs;
    int minval = INT_MAX;
    void next(string& s, int N, int bc, int index, string& temp, int rc){
        if(rc > minval) return;
        if(index == N) {
            if(bc == 0) {
                minval = rc;
                strs.push_back({temp, rc});
            }
            return;
        }
        if(s[index] != '(' && s[index] != ')') {
            temp += s[index];
            next(s, N, bc, index + 1, temp, rc);
            temp.pop_back();
        }
        else next(s, N, bc, index+1, temp, rc+1);
        if(s[index] == '(') {
            if(bc < N / 2) {
                temp += s[index];
                next(s, N, bc + 1, index + 1, temp, rc);
                temp.pop_back();
            }
        }
        else if(s[index] == ')') {
            if(bc > 0) {
                temp += s[index];
                next(s, N, bc - 1, index + 1, temp, rc);
                temp.pop_back();
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int N = s.size();
        string temp = "";
        next(s, N, 0, 0, temp, 0);
        vector<string> ans;
        unordered_set<string> st;
        int minval = strs[strs.size()-1].second;
        for(auto const& curr : strs){
            if(curr.second == minval) st.insert(curr.first);
        }
        for(string str : st) ans.push_back(str);
        return ans;
    }
};