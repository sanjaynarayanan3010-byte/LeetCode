class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int N = nums.size();
        vector<int> n1;
        vector<int> n2;
        n1.push_back(nums[0]);
        n2.push_back(nums[1]);
        for(int i=2;i<N;i++){
            if(n2.back() < n1.back()) n1.push_back(nums[i]);
            else n2.push_back(nums[i]);
        }
        for(int i : n2) n1.push_back(i);
        return n1;
    }
};