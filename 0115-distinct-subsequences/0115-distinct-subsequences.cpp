class Solution {
public:
    int countSeq(int index1,int index2, string &s,string &t,vector<vector<int>>& dp){
        if(index2<0) return 1;
        if(index1<0) return 0;
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        int notEqual=0;
        int notTake=0,take=0;
        if(s[index1]!=t[index2]) {
            notEqual=countSeq(index1-1,index2,s,t,dp);
        }
        else{
            notTake=countSeq(index1-1,index2,s,t,dp);
            take=countSeq(index1-1,index2-1,s,t,dp);
        }
        return dp[index1][index2]=notEqual+notTake+take;
    }
    int numDistinct(string s, string t) {
        int N1=s.size();
        int N2=t.size();
        vector<vector<int>> dp(N1+1,vector<int>(N2+1,-1));
        return countSeq(N1-1,N2-1,s,t,dp);
    }
};