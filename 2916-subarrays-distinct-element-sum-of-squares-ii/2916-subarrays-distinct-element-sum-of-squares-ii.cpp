class Solution {
public:
    int sumCounts(vector<int>& nums) {
        long long mod = 1e9 + 7;
        int N = nums.size();
        vector<long long> cnt(N + 1);
        vector<long long> tot(N + 1);
        unordered_map<int, int> mp;
        long long ans = 0;
        for (int i=0;i<N;i++) {
            int p = mp.count(nums[i]) ? mp[nums[i]] : -1;
            long long c = 0, s = 0;
            for (int idx= N - p - 1; idx>0; idx -= idx & -idx){
                c += cnt[idx];
                s += tot[idx];
            }
            long long gain = (long long)(i - p) * (i - p) - 2 * (s - p * c);
            ans = (ans + (N - i) * gain) % mod;
            for (int idx = N - p; idx <= N; idx += idx & -idx){
                cnt[idx]++;
                tot[idx] += p;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};