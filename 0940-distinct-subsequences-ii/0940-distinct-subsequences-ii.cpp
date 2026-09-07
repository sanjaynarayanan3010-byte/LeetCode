class Solution {
public:
    int distinctSubseqII(string s) {
        int N = s.size();
        long long mod = 1e9 + 7;
        unordered_map<char,long long> mp;
        for(char ch : s) mp[ch] = -1;
        vector<long long> dp(N+1);
        dp[0] = 1;
        for(int i=0;i<N;i++){
            dp[i+1] = (dp[i] * 2) % mod;
            if(mp[s[i]] != -1) {
                dp[i+1] = (mod + dp[i+1] - dp[mp[s[i]]]) % mod;
            }
            mp[s[i]] = i;
        }
        return (dp[N] - 1 + mod) % mod;
    }
};