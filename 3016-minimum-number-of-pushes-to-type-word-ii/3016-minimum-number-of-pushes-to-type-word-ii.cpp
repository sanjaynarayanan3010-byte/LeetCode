class Solution {
public:
    int minimumPushes(string word) {
        vector<int> minFreq(26, 0);
        for(char ch:word){
            minFreq[ch - 'a']++;
        }
        sort(minFreq.begin(), minFreq.end(), greater<int>());
        int ans = 0;
        int currElement = 0;
        int add = 1;
        for(int it:minFreq){
            ans += (add * it);
            currElement++;
            if(currElement % 8 == 0) add++;
        }
        return ans;
    }
};