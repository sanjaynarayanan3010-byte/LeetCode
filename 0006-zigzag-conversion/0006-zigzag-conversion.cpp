class Solution {
public:
    string convert(string s, int numRows) {
        int N = s.size();
        if(numRows == 1) return s;
        vector<string> grid(numRows, "");
        int diff = 1;
        int currIndex = 0;
        for(int i=0;i<s.size();i++){
            grid[currIndex].push_back(s[i]);
            if(currIndex == 0) diff = 1;
            if(currIndex == numRows-1) diff = -1;
            currIndex += diff;
        }
        string ans = "";
        for(string str:grid) {
            for(char ch:str) ans += ch;
        }
        return ans;
    }
};