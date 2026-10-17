class Solution {
public:
    int minSwaps(vector<int>& temp) {
        int N = temp.size();
        vector<pair<int,int>> nums(N);
        for(int i=0;i<N;i++) nums[i] = {temp[i], i};
        sort(nums.begin(), nums.end());
        sort(nums.begin(), nums.end(), [](auto const& a, auto const& b){
            int as = 0, bs = 0;
            int ta = a.first, tb = b.first;
            while(ta) {
                as += (ta % 10);
                ta /= 10;
            }
            while(tb) {
                bs += (tb % 10);
                tb /= 10;
            }
            if(as != bs) return as < bs;
            return a.first < b.first;
        });
        vector<int> vis(N, 0);
        int ans = 0;
        for(int i=0;i<N;i++){
            if(vis[i] || i == nums[i].second) continue;
            int cyc = 0;
            int idx = i;
            while(!vis[idx]){
                vis[idx] = 1;
                cyc++;
                idx = nums[idx].second;
            }
            if(cyc) ans += (cyc - 1);
        }
        return ans;
    }
};