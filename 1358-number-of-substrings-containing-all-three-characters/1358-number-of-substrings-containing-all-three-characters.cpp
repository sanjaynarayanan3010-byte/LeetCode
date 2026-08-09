class Solution {
public:
    int numberOfSubstrings(string s) {
        int N = s.size();
        int count = 0;
        vector<int> f(3, -1);
        for(int i=0;i<N;i++){
            f[s[i] - 'a'] = i;
            if(s[0] != -1 && s[1] != -1 && s[2] != -1){
                count += (min({f[0], f[1], f[2]}) + 1);
            }
        }
        return count;
    }
};