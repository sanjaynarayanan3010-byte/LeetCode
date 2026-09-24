class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int N = nums.size();
        for(int i=0;i<N;i++){
            int s = 0;
            int num = nums[i];
            while(num){
                s += (num % 10);
                num /= 10;
            }
            if(s == i) return i;
        }
        return -1;
    }
};