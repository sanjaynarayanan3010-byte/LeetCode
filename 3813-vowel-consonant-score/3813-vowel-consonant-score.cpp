class Solution {
public:
    int vowelConsonantScore(string s) {
        string vow = "aeiou";
        int vc = 0, cc = 0;
        for(char ch : s) {
            if(isalpha(ch)) {
                if(vow.find(ch) == string::npos) cc++;
            else vc++;
            }
        }
        if(cc > 0) return vc / cc;
        return 0;
    }
};