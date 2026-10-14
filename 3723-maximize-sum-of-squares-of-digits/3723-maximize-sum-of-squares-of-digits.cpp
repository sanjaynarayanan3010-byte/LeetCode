class Solution {
public:
    string maxSumOfSquares(int N, int sum) {
        string ans = "";
        int cs = 0;
        while(N--){
            for(char ch='9';ch>='0';ch--){
                int dig = ch - '0';
                if(cs + dig <= sum) {
                    ans += ch;
                    cs += dig;
                    break;
                }
            }
        }
        if(cs == sum) return ans;
        return "";
    }
};