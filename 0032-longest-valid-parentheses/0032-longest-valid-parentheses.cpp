class Solution {
public:
    int longestValidParentheses(string s) {
        int idx = 0, N = s.size(), ans = 0;
        int oc = 0, cc = 0;
        for(int i=0;i<N;i++){
            if(s[i] == '(') oc++;
            else cc++;
            while(cc > oc) {
                if(s[idx] == ')') cc--;
                else oc--;
                idx++;
            }
            if(cc == oc) ans = max(ans, i - idx + 1);
        }
        oc = 0, cc = 0;
        idx = N-1;
        for(int i=N-1;i>=0;i--){
            if(s[i] == '(') oc++;
            else cc++;
            while(cc < oc) {
                if(s[idx] == ')') cc--;
                else oc--;
                idx--;
            }
            if(cc == oc) ans = max(ans, idx - i + 1);
        }
        return ans;
    }
};