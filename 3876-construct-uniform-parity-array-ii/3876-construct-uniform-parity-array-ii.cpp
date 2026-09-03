class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int> odd;
        for(int i : nums1) {
            if(i & 1) odd.push_back(i);
        }
        sort(odd.begin(), odd.end());
        bool of = 1;
        bool ef = 1;
        for(int i : nums1){
            if(i % 2 == 0) {
                auto it = lower_bound(odd.begin(), odd.end(), i);
                if(it == odd.begin()) {
                    of = 0;
                    break;
                }
            }
        }
        for(int i : nums1){
            if(i & 1) {
                auto it = lower_bound(odd.begin(), odd.end(), i);
                if(it == odd.begin()) {
                    ef = 0;
                    break;
                }
            }
        }
        return of || ef;
    }
};