class Solution {
public:
    string digitSum(string s, int k) {
        string curr = s;
        int size = s.size();
        while(size > k){
            string temp = "";
            int cs = 0;
            for(int i=0;i<size;i++){
                if(i != 0 && i % k == 0) {
                    temp += to_string(cs);
                    cs = 0;
                }
                cs += (curr[i] - '0');
            }
            temp += to_string(cs);
            curr = temp;
            size = curr.size();
        }
        return curr;
    }
};