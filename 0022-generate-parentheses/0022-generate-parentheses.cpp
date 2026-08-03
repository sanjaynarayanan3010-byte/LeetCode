class Solution {
public:
    void gen(vector<string>& ans, int N, int oCount, int cCount, string temp, bool canClose){
        if(temp.size() == N*2){
            if(oCount == N && cCount == 0) ans.push_back(temp);
            return;
        }
        if(oCount < N) gen(ans, N, oCount+1,cCount, temp+'(', 1);
        if(cCount > 0 && canClose) {
            if((N - cCount + 1) == oCount) gen(ans, N, oCount,cCount-1, temp+')', 0);
            else gen(ans, N, oCount,cCount-1, temp+')', 1);
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        gen(ans, n, 0, n, "", 0);
        return ans;
    }
};