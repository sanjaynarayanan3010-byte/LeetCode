class Solution {
public:
    int minRotations(string s) {
        int ans = 0;
        int cv = 0;
        for(char ch : s){
            int d = ch - '0';
            ans += min({abs(d - cv), (d + 10) - cv, (cv + 10) - d});
            cv = d;
        }
        return ans;
    }
};