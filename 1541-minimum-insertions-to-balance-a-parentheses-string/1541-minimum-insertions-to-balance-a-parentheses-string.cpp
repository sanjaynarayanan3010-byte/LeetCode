class Solution {
public:
    int minInsertions(string s) {
        int N = s.size();
        int bc = 0, add = 0;
        for(char ch : s){
            if(ch == '(') {
                bc += 2;
                if(bc & 1) {
                    add++;
                    bc--;
                }
            }
            else{
                bc--;
                if(bc < 0) {
                    bc = 1;
                    add++;
                }
            }
        }
        return bc + add;
    }
};