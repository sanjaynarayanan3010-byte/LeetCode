class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mo = INT_MAX;
        for(int i : nums1) {
            if(i & 1) mo = min(mo, i);
        }
        bool of = 1;
        bool ef = 1;
        for(int i : nums1){
            if(i % 2 == 0) {
                if(i <= mo) {
                    of = 0;
                    break;
                }
            }
        }
        for(int i : nums1){
            if(i & 1) {
                if(i <= mo) {
                    ef = 0;
                    break;
                }
            }
        }
        return of || ef;
    }
};