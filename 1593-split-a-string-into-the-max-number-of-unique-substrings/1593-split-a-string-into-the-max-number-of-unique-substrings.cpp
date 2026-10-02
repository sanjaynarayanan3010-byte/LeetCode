class Solution {
public:
    unordered_set<string> st;
    int ans = 0;
    void sp(string s, int N, int index){
        if(index >= N){
            int size = st.size();
            ans = max(ans, size);
            return;
        }
        for(int i=index;i<N;i++){
            string temp = s.substr(index, i - index + 1);
            if(st.find(temp) == st.end()) {
                st.insert(temp);
                sp(s, N, i+1);
                st.erase(temp);
            }
        }
    }
    int maxUniqueSplit(string s) {
        int N = s.size();
        sp(s, N, 0);
        return ans;
    }
};