class Solution {
public:
    string sortVowels(string s) {
        string vow = "aeiou";
        int N = s.size();
        unordered_map<char,int> mp;
        unordered_map<char, int> fi;
        vector<pair<char, pair<int,int>>> vc;
        for(int i=0;i<N;i++) {
            if(vow.find(s[i]) != string::npos) {
                if(mp[s[i]] == 0) fi[s[i]] = i;
                mp[s[i]]++;
            }
        }
        for(auto p : mp) {
            vc.push_back({p.first,{p.second, fi[p.first]}});
        }
        sort(vc.begin(), vc.end(), [](auto const& a, auto const& b){
            if(a.second.first != b.second.first) return a.second.first > b.second.first;
            return a.second.second < b.second.second;
        });
        string ans = "";
        int index = 0;
        for(char ch : s) {
            if(vow.find(ch) != string::npos) {
                if(vc[index].second.first == 0) index++;
                ans += vc[index].first;
                vc[index].second.first--;
            }
            else ans += ch;
        }
        return ans;
    }
};