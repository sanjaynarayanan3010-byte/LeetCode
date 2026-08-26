class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<string> strs;
        int idx = 0;
        int N = s.size();
        int oc = 0;
        if(k == 1) {
            for(char ch : s){
                if(ch == '1') return "1"; 
            }
            return "";
        }
        for(int i=0;i<N;i++) {
            if(s[i] == '1') {
                idx = i;
                break;
            }
        }
        for(int i=0;i<N;i++){
            if(s[i] == '1') oc++;
            if(oc == k) {
                strs.push_back(s.substr(idx, i - idx + 1));
                idx++;
                while(oc == k) {
                    if(s[idx] == '1') oc--;
                    else idx++;
                }
            }
        }
        if(strs.empty()) return "";
        sort(strs.begin(), strs.end(), [](auto const& a, auto const& b){
            return a.size() < b.size();
        });
        int minSize = strs[0].size();
        vector<string> temp;
        for(string t : strs) {
            if(t.size() == minSize) temp.push_back(t);
        }
        sort(temp.begin(), temp.end());
        return temp[0];
    }
};