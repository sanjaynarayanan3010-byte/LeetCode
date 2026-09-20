class Solution {
public:
    int reverseDegree(string s) {
        int index = 1, ans = 0;
        for(char ch : s) {
            ans += (((int)('z' - ch) + 1) * index);
            index++;
        }
        return ans;
    }
};