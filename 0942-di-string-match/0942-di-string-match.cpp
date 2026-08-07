class Solution {
public:
    vector<int> diStringMatch(string s) {
        int N = s.size();
        vector<int> ans;
        int p1 = 0;
        int p2 = N;
        for(char ch:s){
            if(ch == 'I'){
                ans.push_back(p1);
                p1++;
            }
            else {
                ans.push_back(p2);
                p2--;
            }
        }
        while(p1<=p2) {
            ans.push_back(p1);
            p1++;
        }
        return ans;
    }
};