class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        long long mod = 1e9 + 7;
        int N = nums.size();
        vector<int> freq(32, 0);
        for(int i : nums){
            for(int idx=0;idx<32;idx++){
                if((1 << idx) & i) freq[idx]++;
            }
        }
        long long ans = 0;
        while(k--){
            long long tot = 0;
            for(int i=0;i<32;i++){
                if(freq[i]){
                    tot += (1 << i);
                    freq[i]--;
                }
            }
            ans += (((tot % mod) * (tot % mod)) % mod);
        }
        // for(int i : freq) cout << i << " ";
        return ans % mod;
    }
};