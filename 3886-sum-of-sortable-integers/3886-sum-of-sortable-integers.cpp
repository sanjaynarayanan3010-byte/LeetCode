class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int N = nums.size();
        bool sf = 1;
        for(int i=1;i<N;i++) {
            if(nums[i] < nums[i-1]) sf = 0;
        }
        vector<int> div;
        for(int i=1;i<=N;i++){
            if(!(N % i)) div.push_back(i);
        }
        int sum = accumulate(div.begin(), div.end(), 0);
        if(sf) return sum;
        for(int i : div) cout << i << " ";
        int ans = 0;
        for(int d : div){
            int pmax = -1, maxe = nums[0], mine = nums[0];
            if(d == 1) continue;
            int st = 0, drop = 0, f = 1;
            for(int i=1;i<N;i++){
                if(drop > 1) {
                    f = 0;
                    break;
                }
                if(nums[i-1] > nums[i]) drop++;
                maxe = max(maxe, nums[i]);
                mine = min(nums[i], mine);
                if((i - st + 1) == d){
                    if(!drop || (drop == 1 && nums[i] <= nums[st])) {
                        if(pmax > maxe || mine < pmax) {
                            f = 0;
                            break;
                        }
                        pmax = maxe;
                        if(i + 1 < N) maxe = mine = nums[i+1];
                    }
                    else {
                        f = 0;
                        break;
                    }
                    st = i + 1;
                    i++;
                    drop = 0;
                }
            }
            if(f) ans += d;
        }
        return ans;
    }
};