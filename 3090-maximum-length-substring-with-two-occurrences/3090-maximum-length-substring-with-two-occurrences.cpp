class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<char> mp(26);
        int idx = 0;
        int ans = 0;
        for(int i=0;i<s.size();i++){
            mp[s[i] - 'a']++;
            while(mp[s[i] - 'a'] > 2){
                mp[s[idx] - 'a']--;
                idx++;
            }
            ans = max(ans, i - idx + 1);
        }
        return ans;
    }
};