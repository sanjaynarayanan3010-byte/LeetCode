class Solution {
public:
    void join(vector<int>& leader, int lft, int rt){
        leader[find(leader, lft)] = find(leader, rt);
    }

    int find(vector<int>& leader, int node){
        if(leader[node] != node) {
            leader[node] = find(leader, leader[node]);
        }
        return leader[node];
    }
    int latestDayToCross(int R, int C, vector<vector<int>>& cells) {
        vector<int> leader(R*C+2);
        for(int i=0;i<R*C+2;i++) leader[i] = i;
        vector<bool> water(R*C+2);
        int days = 0;
        int diff[8][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}, {-1,-1}, {1,1}, {-1,1}, {1,-1}};
        for(auto curr:cells){
            int row = curr[0]-1;
            int col = curr[1]-1;
            water[row*C+col+1] = 1;
            for(auto next:diff){
                int cr = row+next[0];
                int cc = col+next[1];
                if(cr>=0 && cc>=0 && cr<R && cc<C && water[cr*C+cc+1]){
                    join(leader, row*C+col+1, cr*C+cc+1);
                }
            }
            if(col == 0) join(leader, 0, row*C+col+1);
            else if(col == C-1) join(leader,row*C+col+1,R*C+1);
            if(find(leader, 0) == find(leader, leader.size()-1)) break;
            days++;
        }
        return days;
    }
};