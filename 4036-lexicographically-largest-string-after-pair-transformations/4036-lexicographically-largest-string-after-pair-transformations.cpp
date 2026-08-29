class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        map<long,char> mp;
        vector<string> str;
        long c = 1;
        char ch = 'a';
        for(int i=0;i<26 && ch <= 'z';i++,ch++){
            mp[c] = ch;
            c *= 2;
        }

        for(int i : nums){
            vector<int> temp;
            for(auto it : mp){
                if(it.first > i) break;
                temp.push_back(it.first);
            }
            string s = "";
            for(int idx=temp.size()-1;idx>=0;idx--){
                while(i >= temp[idx]){
                    s += mp[temp[idx]];
                    i -= temp[idx];
                }
            }
            str.push_back(s);
        }
        return str;
    }
};