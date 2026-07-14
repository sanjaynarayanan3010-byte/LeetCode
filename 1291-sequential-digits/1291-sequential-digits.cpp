class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int p1=1;p1<=8;p1++){
            int currNum = p1*10;
            int currLast = p1;
            for(int p2=p1+1;p2<=9;p2++){
                currNum += p2;
                if(currNum>=low && currNum<=high && p2==currLast+1) ans.push_back(currNum);
                currLast = currNum%10;
                currNum *= 10;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};