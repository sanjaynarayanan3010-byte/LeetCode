class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& grid) {
        int N = n;
        unordered_map<int,vector<int>> mp;
        for(auto curr:grid){
            mp[curr[0]].push_back(curr[1]);
        }
        vector<int> vis(N,0);
        queue<int> q;
        q.push(k);
        while(!q.empty()){
            int currNode = q.front();
            q.pop();

            vis[currNode] = 1;
            for(int i:mp[currNode]){
                if(!vis[i]){
                    q.push(i);
                }
            }
        }
        for(int i:vis) cout<<i<<" ";
        vector<int> ans;
        bool con = 0;
        for(auto curr:grid){
            if(!vis[curr[0]] && vis[curr[1]]){
                con = 1;
                break;
            }
        }
        if(!con){
            for(int i=0;i<N;i++) {
                if(!vis[i]) ans.push_back(i);
            }
        }
        else {
            for(int i=0;i<N;i++) ans.push_back(i);
        }
        return ans;
    }
};