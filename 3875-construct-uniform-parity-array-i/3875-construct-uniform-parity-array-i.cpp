class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oc = 0;
        for(int i : nums1) {
            if(i & 1) oc++;
        }
        bool ef = 1;
        for(int i : nums1) {
            if(i & 1) {
                if(!oc) {
                    ef = 0;
                    break;
                }
            }
        }
        bool of = 1;
        for(int i : nums1){
            if(i % 2 == 0) {
                if(!oc) {
                    of = 0;
                    break;
                }
            }
        }
        return ef || of;
    }
};