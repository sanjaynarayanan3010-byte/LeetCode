class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int N = nums.size();
        vector<int> cnt;
        int c = 0;
        for(int i : nums){
            if(i == 1) c++;
            else {
                if(c) {
                    cnt.push_back(c);
                    c = 0;
                }
            }
        }
        if(c) cnt.push_back(c);
        // for(int i : cnt) cout << i << " ";
        // cout << endl;
        int index = 0;
        bool of = 0;
        for(int i=0;i<N;i++){
            if(nums[i] == 1) {
                nums[i] = cnt[index];
                of = 1;
            }
            else {
                if(of && nums[i-1] != 0) index++;
            }
        }
        if(!of) return 0;
        // for(int i : nums) cout << i << " ";
        int ans = *max_element(cnt.begin(), cnt.end()) - 1;
        for(int i=0;i<N;i++){
            if(nums[i] == 0 && i == 0) ans = max(ans, nums[i+1]);
            else if(nums[i] == 0 && i == N-1) ans = max(ans, nums[i-1]);
            else if(nums[i] == 0){
                ans = max(nums[i-1] + nums[i+1], ans);
            }
        }
        return ans;
    }
};