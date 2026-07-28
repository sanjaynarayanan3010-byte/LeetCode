class Solution {
public:
    int find(vector<int>& leader, int node){
        if(leader[node] != node){
            leader[node] = find(leader, leader[node]);
        }
        return leader[node];
    }

    void join(vector<int>& leader, int lt, int rt){
        leader[find(leader, rt)] = find(leader, lt);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        vector<int> leader(N+1,0);
        for(int i=1;i<=N;i++) leader[i] = i;
        vector<int> groupCount(N+1,0);
        for(int i=0;i<N;i++){
            for(int idx=0;idx<N;idx++){
                if(i != idx && isConnected[i][idx]){
                    join(leader,i+1, idx+1);
                }
            }
        }
        int count = 0;
        for(int i=1;i<=N;i++){
            int ult = find(leader, i);
            groupCount[ult]++;
            if(groupCount[ult] == 1) count++;
        }
        return count;
    }
};