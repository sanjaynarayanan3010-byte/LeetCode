class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int ans = 0, N = nums.size();
        for(int i=0;i<N;i++){
            unordered_map<int,int> mp;
            vector<int> dup;
            for(int idx=i;idx<N;idx++){
                if(!mp[nums[idx]]) dup.push_back(nums[idx]);
                mp[nums[idx]]++;
                int cnt = 1, f = 1;
                for(int d : dup){
                    if(mp[d] != cnt) {
                        f = 0;
                        break;
                    }
                    cnt++;
                }
                if(f) ans++;
            }
        }
        return ans;
    }
};