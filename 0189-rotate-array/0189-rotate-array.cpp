class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int turn = k % nums.size();
        int N = nums.size();
        for(int i=0;i<N - turn;i++){
            nums.push_back(nums[i]);
        }
        nums.erase(nums.begin(), nums.begin() + (N - turn));
    }
};