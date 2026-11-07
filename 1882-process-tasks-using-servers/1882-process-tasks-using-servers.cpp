class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        for(int i=0;i<servers.size();i++) q.push({servers[i], i});
        priority_queue< tuple<long long,int,int>, vector<tuple<long long,int,int>>, greater<tuple<long long,int,int>>> endtimes;
        vector<int> ans(tasks.size());
        long long ct = 0;
        for(int i=0;i<tasks.size();i++){
            ct = max(i * 1LL, ct);
            while(!endtimes.empty() && ct >= get<0>(endtimes.top())){
                auto [toptime, topserver, topindex] = endtimes.top();
                endtimes.pop();
                q.push({topserver, topindex});
            }
            if(q.empty()){
                auto [toptime, topserver, topindex] = endtimes.top();
                ct = toptime;
                endtimes.pop();
                q.push({topserver, topindex});
            }
            auto [server, index] = q.top();
            ans[i] = index;
            endtimes.push(make_tuple((long long)(ct + tasks[i]), server, index));
            q.pop();
        }
        return ans;
    }
};