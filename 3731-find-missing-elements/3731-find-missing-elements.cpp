class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minElement = *min_element(nums.begin(), nums.end());
        int maxElement = *max_element(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int currIndex = 0;
        for(int i=minElement; i<=maxElement, currIndex<nums.size(); i++,currIndex++){
            while(i<=maxElement && i != nums[currIndex]){
                ans.push_back(i);
                i++;
            }
        }
        return ans;
    }
};