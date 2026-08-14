class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> mp;
        int idx = 0;
        int ans = 0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            while(mp[s[i]] > 2){
                mp[s[idx]]--;
                idx++;
            }
            ans = max(ans, i - idx + 1);
        }
        return ans;
    }
};