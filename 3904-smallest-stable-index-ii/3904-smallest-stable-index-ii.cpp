class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int N=nums.size();
        vector<int> Lmax(N+1,0);
        vector<int> Rmin(N+1);
        Lmax[0]=nums[0];
        for(int i=1;i<N;i++){
            Lmax[i]=max(Lmax[i-1],nums[i]);
        }
        Rmin[N]=nums[N-1];
        for(int i=nums.size()-1;i>=0;i--){
            Rmin[i]=min(Rmin[i+1],nums[i]);
        }
        int count=0;
        for(int i=0;i<N;i++){
            if(Lmax[i]-Rmin[i]<=k) return i;
        }
        return -1;
    }
};