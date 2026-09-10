class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int N = s.size();
        unordered_map<string, int> dup;
        for(string temp : words){
            dup[temp]++;
        }
        int M = words.size();
        int checksize = words[0].size();
        vector<int> stp;

        for(int i=0;i<checksize;i++){
            int lt = i, rt = i;
            int c = 0;
            unordered_map<string, int> mp;
            while(rt + checksize <= N){
                string t = s.substr(rt, checksize);
                rt += checksize;
                if(dup.count(t)){
                    mp[t]++;
                    c++;
                    while(mp[t] > dup[t]) {
                        string rem = s.substr(lt, checksize);
                        mp[rem]--;
                        lt += checksize;
                        c--;
                    }
                    if(c == M){
                        stp.push_back(lt);  
                    }
                }
                else {
                    mp.clear();
                    c = 0;
                    lt = rt;
                }
            }
        }
        return stp;
    }
};