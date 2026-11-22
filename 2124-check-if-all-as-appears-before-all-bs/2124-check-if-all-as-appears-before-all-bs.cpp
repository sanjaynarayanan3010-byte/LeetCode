class Solution {
public:
    bool checkString(string s) {
        bool bf = 0;
        for(char ch : s) {
            if(ch == 'a' && bf) return 0;
            if(ch == 'b') bf = 1;
        }
        return 1;
    }
};