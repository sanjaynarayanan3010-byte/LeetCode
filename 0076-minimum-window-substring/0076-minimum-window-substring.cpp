class Solution {
public:
    string minWindow(string s, string t) {
        int N = s.size();
        int M = t.size();
        if(M > N) return "";
        unordered_map<char, int> mp;
        for(char ch:t) {
            mp[ch]++;
        }
        int idx = 0;
        int sti = -1;
        int minL = INT_MAX;
        int c = 0;
        for(int i=0;i<N;i++){
            if(mp[s[i]] > 0) c++;
            mp[s[i]]--;
            while(c == M){
                if(minL > i - idx + 1) {
                    minL = i - idx + 1;
                    sti = idx;
                }
                mp[s[idx]]++;
                if(mp[s[idx]] > 0) c--;
                idx++;
            }
        }
        if(sti == -1) return "";
        return s.substr(sti, min(minL, N - sti));
    }
};