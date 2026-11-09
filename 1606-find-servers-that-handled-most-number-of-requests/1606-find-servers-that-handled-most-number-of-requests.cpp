class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arr, vector<int>& load) {
        int N = arr.size();
        priority_queue<tuple<int,int>, vector<tuple<int,int>>, greater<tuple<int,int>>> q;
        set<int> free;
        vector<int> freq(k, 0);
        for(int i=0;i<k;i++) free.insert(i);
        for(int i=0;i<N;i++){
            while(!q.empty() && get<0>(q.top()) <= arr[i]) {
                auto [toptime, topserver] = q.top();
                free.insert(topserver);
                q.pop();
            }
            int cs = i % k, nt = load[i] + arr[i];
            auto lb = free.lower_bound(cs);
            if(lb == free.end()) {
                if(free.size() != 0) lb = free.begin();
                else continue;
            }
            q.push(make_tuple(nt, *lb));
            freq[*lb]++;
            free.erase(lb);
        }
        vector<int> ans;
        int me = *max_element(freq.begin(), freq.end());
        for(int i=0;i<k;i++) {
            if(freq[i] == me) ans.push_back(i);
        }
        return ans;
    }
};