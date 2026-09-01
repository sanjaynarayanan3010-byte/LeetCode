class Solution {
public:
    bool isBalanced(string num) {
        int  os = 0, es = 0;
        for(int i=0;i<num.size();i++) {
            if(i & 1) os += (num[i] - '0');
            else es += (num[i] - '0');
        }
        return os == es;
    }
};