class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int N = nums1.size();
        int mv = 0;
        vector<int> diff;
        for(int i=0;i<N;i++) {
            diff.push_back(abs(nums1[i] - nums2[i]));
            mv = max(mv, abs(nums1[i] - nums2[i]));
        }
        vector<long long> cnt(mv + 1, 0);
        for(int i : diff) cnt[i]++;
        long long tot = k1 + k2;
        long long ans = 0;
        for(int i=mv;i>=1;i--){
            if(!tot) break;
            if(cnt[i] > tot) {
                cnt[i-1] += tot;
                cnt[i] -= tot;
                tot = 0;
            }
            else {
                tot -= cnt[i];
                cnt[i-1] += cnt[i];
                cnt[i] = 0;
            }
        }
        for(int i=1;i<cnt.size();i++) ans += (long long)(cnt[i] * i * i);
        return ans;
    }
};