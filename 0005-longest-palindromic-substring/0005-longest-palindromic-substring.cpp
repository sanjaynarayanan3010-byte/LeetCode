class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        ans += s[0];
        int maxLen = 1;
        int N = s.size();

        for(int i=0;i<N;i++){
            // odd length
            int p1 = i, p2 = i;
            while(p1 >= 0 && p2 < N && s[p1] == s[p2]){
                p1--;
                p2++;
            }
            if((p2 - p1 - 1) > maxLen){
                maxLen = (p2 - p1 - 1);
                ans = s.substr(p1+1, maxLen);
            }

            //even length
            p1 = i;p2 = i+1;
            while(p1 >= 0 && p2 < N && s[p1] == s[p2]){
                p1--;
                p2++;
            }
            if((p2 - p1 - 1) > maxLen){
                maxLen = (p2 - p1 - 1);
                ans = s.substr(p1+1, maxLen);
            }
        }
        return ans;
    }
};