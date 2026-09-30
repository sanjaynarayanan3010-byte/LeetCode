class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        int N = s.size();
        vector<int> freq(2, 0);
        int f = 0;
        vector<int> ans(N, 0);
        for(int i=0;i<N;i++){
            if(s[i] == '('){
                if(freq[1] > freq[0]) f = 0;
                else if(freq[0] > freq[1]) f = 1;
                freq[f]++;
            }
            else {
                if(freq[1] < freq[0]) f = 0;
                else if(freq[0] < freq[1]) f = 1;
                freq[f]--;
            }
            ans[i] = f;
        }
        return ans;
    }
};