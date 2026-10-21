class Solution {
public:
    int minOperations(string s) {
        string sorted = s;
        sort(sorted.begin(), sorted.end());
        string temp = s;
        if(s == sorted) return 0;
        sort(s.begin(), s.end()-1);
        sort(temp.begin()+1, temp.end());
        if(s == sorted || temp == sorted) return 1;
        sort(s.begin()+1, s.end());
        sort(temp.begin(), temp.end()-1);
        if(s == sorted || temp == sorted) return 2;
        sort(s.begin(), s.end()-1);
        sort(temp.begin()+1, temp.end());
        if(s == sorted || temp == sorted) return 3;
        return -1;
    }
};