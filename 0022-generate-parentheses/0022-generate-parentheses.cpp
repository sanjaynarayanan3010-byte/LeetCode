class Solution {
public:
    void gen(vector<string>& ans, int N, int oCount, int cCount, string temp){
        if(temp.size() == N*2){
            ans.push_back(temp);
            return;
        }
        if(oCount < N) gen(ans, N, oCount+1,cCount, temp+'(');
        if(cCount < oCount) gen(ans, N, oCount,cCount+1, temp+')');

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        gen(ans, n, 0, 0, "");
        return ans;
    }
};