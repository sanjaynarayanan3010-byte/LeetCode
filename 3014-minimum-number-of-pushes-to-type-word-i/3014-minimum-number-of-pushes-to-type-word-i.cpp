class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        int N = word.size();
        if(N > 24) {
            ans += (N - 24) * 4;
            N = 24;
        }
        if(N > 16){
            ans += (N - 16) * 3;
            N = 16;
        }
        if(N > 8) {
            ans += (N - 8) * 2;
            N = 8;
        }
        ans += N;
        return ans;
    }
};