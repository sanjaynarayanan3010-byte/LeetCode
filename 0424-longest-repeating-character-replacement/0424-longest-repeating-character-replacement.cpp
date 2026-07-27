class Solution {
public:
    int characterReplacement(string s, int k){
        int N = s.size();
        int ans = 0;
        for(char ch='A';ch<='Z';ch++){
            int left = 0, bal = k;
            for(int i=0;i<N;i++){
                if(ch != s[i]){
                    while(bal == 0){
                        if(s[left] != ch) bal++;
                        left++;
                    }
                    bal--;
                }
                ans = max(ans, i - left + 1);
            }
        }
        return ans;
    }
};