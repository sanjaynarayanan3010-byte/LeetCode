class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> mp;
        for(auto curr : edges){
            mp[curr[0]].push_back(curr[1]);
            mp[curr[1]].push_back(curr[0]);
        }
        vector<bool> vis(n + 1, 0);
        queue<int> q;
        q.push(source);
        vis[source] = 1;
        while(!q.empty()){
            int currNode = q.front();
            q.pop();

            for(int i:mp[currNode]){
                if(!vis[i]){
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
        return vis[destination];
    }
};