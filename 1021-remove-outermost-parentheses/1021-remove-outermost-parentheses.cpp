class Solution {
public:
    string removeOuterParentheses(string s) {
        string temp = "";
        string ans = "";
        int bc = 0;
        for(char ch : s){
            if(bc == 0 && ch == '(') {
                bc++;
                continue;
            }
            if(bc == 1 && ch == ')') {
                bc--;
                ans += temp;
                temp = "";
                continue;
            }
            if(ch == '(') bc++;
            else bc--;
            temp += ch;
        }
        return ans;
    }
};