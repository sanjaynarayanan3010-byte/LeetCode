class Solution {
public:
    bool rotateString(string s, string goal) {
        int N = s.size();
        string temp;
        temp = goal;
        for(char ch:temp){
            goal += ch;
        }
        return goal.find(s) != string::npos;
    }
};