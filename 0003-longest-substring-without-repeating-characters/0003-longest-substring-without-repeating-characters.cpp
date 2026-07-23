class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;

        int maxLen = 1;
        int p1 = 0;
        int p2 = 0;

        unordered_set<char> st;

        while(p1<s.size() && p2<s.size()){
            if(!st.contains(s[p2])){
                st.insert(s[p2]);
                p2++;
            }
            else{
                st.erase(s[p1]);
                p1++;
            }
            if(st.size() > maxLen) maxLen = st.size();
        }
        return maxLen;
    }
};