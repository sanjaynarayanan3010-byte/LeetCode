class Solution {
public:
    bool next(string& s, int oc, int cc, int N, int index, vector<vector<vector<int>>>& dp){
        if(index == N) {
            if(oc == cc) return 1;
            return 0;
        }
        bool op = 0, cl = 0, sk = 0, nt = 0;
        if(dp[oc][cc][index] != -1) return dp[oc][cc][index];
        if(s[index] == '(') {
            if(oc < N / 2) nt = next(s, oc + 1, cc, N, index+1, dp);
            else return dp[oc][cc][index] = 0;
        }
        else if(s[index] == '*'){
            sk = next(s, oc, cc, N, index+1, dp);
            if(oc < N / 2) op = next(s, oc + 1, cc, N, index+1, dp);
            if(oc > cc) cl = next(s, oc, cc + 1, N, index+1, dp);
        }
        else {
            if(oc > cc) nt = next(s, oc, cc + 1, N, index + 1, dp);
            else return dp[oc][cc][index] = 0;
        }
        return dp[oc][cc][index] = sk || cl || op || nt;
    }

    bool checkValidString(string s) {
        int N = s.size();
        int oc = 0, cc = 0;
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(N, -1)));
        return next(s, oc, cc, N, 0, dp);
    }
};