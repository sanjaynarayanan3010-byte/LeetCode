class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char sep) {
        vector<string> ans;
        for(string s : words){
            string nosep = "";
            for(char ch : s){
                if(ch == sep){
                    if(nosep.size() == 0) continue;
                    ans.push_back(nosep);
                    nosep = "";
                }
                else nosep += ch;
            }
            if(nosep.size() > 0) ans.push_back(nosep);
        }
        return ans;
    }
};