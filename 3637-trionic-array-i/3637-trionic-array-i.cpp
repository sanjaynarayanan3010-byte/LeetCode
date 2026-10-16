class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p = 0, q = -1;
        int N = nums.size();
        vector<int> pr;
        vector<int> qr;
        vector<int> rest;
        for(;p<N-1;p++){
            pr.push_back(nums[p]);
            if(nums[p] >= nums[p+1]) {
                break;
            }
        }
        for(q=p;q<N-1;q++){
            qr.push_back(nums[q]);
            if(nums[q] <= nums[q+1]){
                break;
            }
        }
        rest.push_back(nums[q]);
        for(int i=q+1;i<N;i++){
            rest.push_back(nums[i]);
            if(nums[i] <= nums[i-1]) return 0;
        }
        if(pr.size() > 1 && qr.size() > 1 && rest.size() > 1 && pr.size() + qr.size() + rest.size() == N + 2) return 1;
        return 0;
    }
};