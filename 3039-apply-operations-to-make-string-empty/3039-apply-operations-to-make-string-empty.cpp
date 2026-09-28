class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<char, int> mp;
        for(char ch : s) mp[ch]++;
        unordered_set<char> st;
        vector<char> zeros;
        while(true){
            bool f = 0;
            for(auto it : mp) {
                if(it.second > 1) f = 1;
            }
            if(f == 0) {
                break;
            }
            for(auto& it : mp) {
                it.second--;
                if(it.second == 0) zeros.push_back(it.first);
            }
        }
        for(char ch : zeros) mp.erase(ch);
        for(auto it : mp) st.insert(it.first);
        string ans = "";
        for(int i=s.size()-1;i>=0;i--) {
            if(st.find(s[i]) != st.end()) {
                ans += s[i];
                st.erase(s[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};