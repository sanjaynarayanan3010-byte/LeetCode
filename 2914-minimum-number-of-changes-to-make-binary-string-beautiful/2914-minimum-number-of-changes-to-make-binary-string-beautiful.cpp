class Solution {
public:
    int minChanges(string s) {
        int N = s.size();
        if(N < 2) return 0;
        if(N == 2) {
            if(s[0] == s[1]) return 0;
            return 1;
        }
        int zc = 0, oc = 0, ans = 0;
        for(int i=0;i<N;i++){
            if(s[i] == '0') {
                if(oc & 1) {
                    ans++;
                    oc = 0;
                    continue;
                }
                zc++;
            }
            else {
                if(zc & 1) {
                    ans++;
                    zc = 0;
                    continue;
                }
                oc++;
            }
        }
        if(oc & 1) ans++;
        else if(zc & 1) ans++;
        return ans;
    }
};